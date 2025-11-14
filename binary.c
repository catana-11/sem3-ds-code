#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root;

 void create_nr(struct node *root){

    struct node *temp, *curr;
    char cont = 'y'; char choice = 'l';
    int flag = 0;

    while (cont == 'y'){
        temp = root;
        flag = 0;

        curr = (struct node *)malloc(sizeof(struct node));
        curr->left = curr->right = NULL;

        printf("\nEnter the new node data: "); scanf("%d", &curr->data);

        while(flag == 0){

            printf("\nDo you want to attach the new node to l or r of %d: ", temp->data); scanf(" %c", &choice);

            if (choice=='l'){

                if (temp->left == NULL){
                    temp->left = curr;
                    flag = 1;
                }
                temp = temp->left;
            }

            else{

                if (temp->right == NULL){
                    temp->right = curr;
                    flag = 1;
                }
                temp = temp->right;
            }

        } // this while ends => node is attached, ask for new node
        printf("\nDo you want to attach new node?: "); scanf(" %c", &cont);
    }
 }

// stacks-->

struct node  *stack[20];
int top = -1;

void push(struct node *temp){

    top++;
    stack[top] = temp;

}

struct node *pop(){
    struct node *temp = stack[top];
    top--;
    return temp;
}

void inorder_nr(struct node *root){

    struct node *temp= root;
    top = -1;
    
    while(1){

        while (temp!=NULL){
            push(temp);
            temp = temp->left;
        }

        if (top == -1){break;}

        temp = pop();
        printf("[%d]", temp->data);

        temp = temp->right;
    }

}

void preorder_nr(struct node *root){

    struct node *temp= root;
    top = -1;
    while(1){

        while (temp!=NULL){
            printf("[%d]", temp->data);
            push(temp);
            temp = temp->left;
        }

        if (top == -1){break;}

        temp = pop();
        
        temp = temp->right;
    }

}

void postorder_nr(struct node *root){

    struct node *temp= root;
    top = -1;
    while(1){

        while (temp!=NULL){
            push(temp);
            temp = temp->left;
        }

        if (stack[top]->right!=NULL){temp = pop(); printf("[%d]", temp->data);}

        while (top!=-1 && stack[top]->right == temp){temp = pop(); printf("[%d]", temp->data);}

        if (top == -1){break;}

        temp = stack[top]->right;
    }

}

//queue -->
struct node *queue[100];
int f = -1;
int r = -1;

void enqueue(struct node *temp){
    r++;
    queue[r] = temp;
}

struct node *dequeue(){
    struct node * temp;
    f++;
    temp = queue[f];
    return temp;

}

void queue_traversal_nr(struct node *root){


    struct node *temp = root;
    enqueue(temp);

    while(f!=r){
        temp = dequeue();
        printf("[%d]", temp->data);
        if (temp->left!=NULL) {enqueue(temp->left);}
        if (temp->right!=NULL) {enqueue(temp->right);}        
    }
}

struct node *copy_r(struct node *root){

    struct node *temp = NULL;

    if (root!=NULL){
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = root->data;
        temp->left = copy_r(root->left);
        temp->right = copy_r(root->right);
    }

    return temp;

}

int depth_nr(struct node *root){
    top = -1;
    struct node *temp = root;

    int d = 0;

    while(1){

        while(temp!=NULL){
            push(temp);
            temp = temp->left;
            if (d<top){d = top;}
        }

        if (stack[top]->right!=NULL){temp = pop();}

        while(top>=0 && stack[top]->right==temp){temp = pop();}

        if (top==-1) break;

        temp = stack[top]->right;
    }

    return d+1;

}


void mirror_r(struct node *root){

    struct node *temp;

    temp = root->left;
    root->left = root->right;
    root->right = temp;


    if (root->left == NULL) mirror_r(root->left);
    if (root->right ==NULL) mirror_r(root->right);

}


int main(){

    root = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter root data: "); scanf("%d", &root->data);
    root->left = root->right =  NULL;

    create_nr(root);
    inorder_nr(root);
    printf("\n");
    preorder_nr(root);
    printf("\n");
    postorder_nr(root);
    printf("\n");
    queue_traversal_nr(root);
    printf("\nNow making copy: ");
    struct node *root1 = copy_r(root);
    
    inorder_nr(root1);

    printf("\nDepth: %d", depth_nr(root));

    printf("\nNow mirroring: ");
    mirror_r(root);
    inorder_nr(root);





    return 0;
}