/*
normal binary tree operations:
create, delete, traversal, mirror, copy
 */

 #include <stdio.h>
 #include <stdlib.h>

 // DATA --->

 struct node{
    int data;
    struct node *left;
    struct node *right;
 };

 struct node *root, *root1;

 // CREATIONS --->

 void create_r(struct node *root){
    struct node *temp = root;

    char choice='y';

    printf("\nAttach node to l of %d?: ", temp->data); scanf(" %c", &choice);

    if (choice=='y'){
        struct node *curr;
        curr = (struct node*)malloc(sizeof(struct node));
        printf("\nEnter node data: "); scanf("%d", &curr->data);
        curr->left = curr->right = NULL;

        temp->left = curr;
        create_r(curr);
    }

    printf("\nAttach node to r of %d?: ", temp->data); scanf(" %c", &choice);
    if (choice == 'y'){
        struct node *curr;
        curr = (struct node*)malloc(sizeof(struct node));
        printf("\nEnter node data: "); scanf("%d", &curr->data);
        curr->left = curr->right = NULL;

        temp->right = curr;
        create_r(curr);
    }
 }

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

 // TRAVERSALS --->

 void inorder_r(struct node *temp){
    if (temp!=NULL){
        inorder_r(temp->left);
        printf("    [%d]", temp->data);
        inorder_r(temp->right);
    }
 }

void preorder_r(struct node *temp){
    if (temp!=NULL){
        
        printf("    [%d]", temp->data);
        preorder_r(temp->left);
        preorder_r(temp->right);
    }
 }

void postorder_r(struct node *temp){
    if (temp!=NULL){
        postorder_r(temp->left);
        postorder_r(temp->right);
        printf("    [%d]", temp->data);
    }
}

// STACK for non rec traversals -->

struct node *stack[100];
int top = -1;

int stack_empty(){
    if (top == -1){
        return 1;
    }
    return 0;
 }

void push(struct node *temp){
    top++;
    stack[top] = temp;
}

struct node *pop(){
    if (stack_empty() == 1) {printf("Stack is empty"); return NULL;}
    else{
        struct node *temp = stack[top];
        top--;
        return temp;
    }
}

void inorder_nr(struct node *root){

    struct node *temp;
    temp = root;
    top = -1;
 
    while(1){

        while(temp!=NULL){
            push(temp);
            temp = temp->left;
        }

        if (stack_empty() == 1) break;

        temp = pop();
        printf("\n  [%d]", temp->data);

        temp = temp->right;
    }
}


void preorder_nr(struct node *root){

    struct node *temp;
    temp = root;
    top = -1;
 
    while(1){

        while(temp!=NULL){
            printf("\n  [%d]", temp->data);
            push(temp);
            temp = temp->left;
        }

        if (stack_empty() == 1) break;

        temp = pop();
        
        temp = temp->right;
    }
}

void postorder_nr(struct node *root){

    struct node *temp;
    temp = root; top = -1;
 
    while(1){

        while(temp!=NULL){
            push(temp);
            temp = temp->left;
        }
        
        if (stack[top]->right !=NULL){
            temp = pop();
            printf("\n  [%d]", temp->data);
        }

        while (stack_empty()==0 && stack[top]->right == temp){
            temp = pop();
            printf("\n  [%d]", temp->data);
        }
        if (stack_empty() == 1) break;
        temp = stack[top]->right;
    }
}

// QUEUE traversal --->

struct node *queue[100];

int f = -1; int r = -1;

void enqueue(struct node *temp){

    r++;
    queue[r] = temp;
}

struct node *dequeue(){
    f++;
    struct node *temp = queue[f];
    return temp;
}

void queue_traversal(struct node *root){

    struct node *temp = root;
    enqueue(temp);

    while(f!=r){
        temp = dequeue();
        printf("    [%d]", temp->data);

        if (temp->left!=NULL){enqueue(temp->left);}
        if (temp->right!=NULL){enqueue(temp->right);}
    }
}

struct node *copy_r(struct node *root){
    // Returns the new copied tree node
    struct node *temp = NULL;

    if (root!=NULL){
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = root->data;
        temp->left = copy_r(root->left);
        temp->right = copy_r(root->right);
    }

    return temp;

}

void copy_nr(struct node *old_root, struct node *new_root) {
    if (old_root == NULL) {
        new_root = NULL;
        return;
    }

    // Copy root data
    new_root->data = old_root->data;
    new_root->left = new_root->right = NULL;

    // Two stacks to hold nodes of old and new trees
    struct node *stack_old[100];
    struct node *stack_new[100];
    int top = -1;

    struct node *temp_old = old_root;
    struct node *temp_new = new_root;

    while (1) {
        while (temp_old != NULL) {
            // If old has left, allocate in new
            if (temp_old->left != NULL) {
                temp_new->left = (struct node *)malloc(sizeof(struct node));
                temp_new->left->data = temp_old->left->data;
                temp_new->left->left = temp_new->left->right = NULL;
            }

            // If old has right, allocate in new
            if (temp_old->right != NULL) {
                temp_new->right = (struct node *)malloc(sizeof(struct node));
                temp_new->right->data = temp_old->right->data;
                temp_new->right->left = temp_new->right->right = NULL;
            }

            // Push both nodes to stacks
            stack_old[++top] = temp_old;
            stack_new[top] = temp_new;

            // Move to left subtree
            temp_old = temp_old->left;
            temp_new = temp_new->left;
        }

        if (top == -1)
            break;

        // Pop both stacks
        temp_old = stack_old[top];
        temp_new = stack_new[top];
        top--;

        // Move to right subtree
        temp_old = temp_old->right;
        temp_new = temp_new->right;
    }

    printf("\nBinary tree copied (non-recursive) successfully.\n");
}

int depth_r(struct node *root) {
    int t1 = 0, t2 = 0;
    if (root == NULL)
        return 0;
    else {
        t1 = depth_r(root->left);
        t2 = depth_r(root->right);
        if (t1 > t2)
            return ++t1;
        else
            return ++t2;
    }
}

int depth_nr(struct node *root) {
    if (root == NULL)
        return 0;

    int d = 0;
    struct node *temp = root;
    top = -1;

    while (1) {
        while (temp != NULL) {
            push(temp);
            temp = temp->left;
            if (d < top)  // track maximum stack height
                d = top;
        }

        // If no right child, pop
        if (stack[top]->right == NULL) { temp = pop();}

        // Pop already processed right subtrees
        while (!stack_empty() && stack[top]->right == temp) {
            temp = pop();
        }

        if (stack_empty()) break;

        // Move to right child
        temp = stack[top]->right;
    }

    return d + 1;
}

void mirror_r(struct node *root){
    struct node *temp;

    temp = root->left;
    root->left = root->right;
    root->right = temp;

    if (root->left!=NULL) mirror_r(root->left);
    if (root->right!=NULL) mirror_r(root->right);
}

void mirror_nr(struct node *root){

    struct node *temp = root;
    enqueue(temp);

    while(f!=r){
        temp = dequeue();

        struct node *tempswitch = (struct node *)malloc(sizeof(struct node));

        tempswitch = temp->left;
        temp->left = temp->right;
        temp->right = tempswitch;
    
        if (temp->left!=NULL){enqueue(temp->left);}
        if (temp->right!=NULL){enqueue(temp->right);}
    }
}

 int main(){

    int x; int contswitch = 1;
    struct node *new_root;

    root = (struct node *)malloc(sizeof(struct node));
    root->left = root->right = NULL;
    root1 = (struct node *)malloc(sizeof(struct node));
    root1->left = root1->right = NULL;
    printf("\nEnter data of root: "); scanf("%d", &root->data);

    while(contswitch == 1){

        printf("\n---MENU---\n1. Create recursive\n2. Create nonrec\n3. Inorder rec"); 
        printf("\nEnter your choice: "); scanf("%d", &x);

        switch (x) {

            case 1:
                printf("\nCreating tree using recursive-->");
                create_r(root);
                break;

            case 2:
                printf("\nCreating tree using nonrecursive-->");
                printf("\nEnter data of new root: "); scanf("%d", &root1->data);
                create_nr(root1);
                break;

            case 3:
                printf("\nPrinting the tree (inorder recursive): ");
                inorder_r(root);
                printf("\n");
                inorder_r(root1);
                break;

            case 4:
                printf("\nPrinting the tree (preorder recursive): ");
                preorder_r(root);
                printf("\n");
                preorder_r(root1);
                break;

            case 5:
                printf("\nPrinting the tree (postorder recursive): ");
                postorder_r(root);
                printf("\n");
                postorder_r(root1);
                break;

            case 6:
                top = -1;
                printf("\nPrinting tree (inorder nonrec)");
                inorder_nr(root); printf("\n");
                inorder_nr(root1);
                break;

            case 7:
                top = -1;
                printf("\nPrinting tree (preorder nonrec)");
                preorder_nr(root); printf("\n");
                preorder_nr(root1);
                break;

            case 8:
                top = -1;
                printf("\nPrinting tree (postorder nonrec)");
                postorder_nr(root); printf("\n");
                postorder_nr(root1);
                break;

            case 9:
                printf("\nBreadth first traversal: ");
                queue_traversal(root1);
                break;

            case 10:
                printf("\nCopying into a new tree");
                struct node *newtree = copy_r(root1);

                queue_traversal(newtree);
                break;

            case 11:
                new_root = (struct node *)malloc(sizeof(struct node));

                printf("\nCopying tree non-recursively (root → root1)...");
                copy_nr(root1, new_root);
                printf("\nCopied tree (inorder recursive): ");
                inorder_r(new_root);
                break;

            case 12:
             
                printf("\nDepth of tree is: %d", depth_r(root1));
                printf("\nNon rec Depth of tree is: %d", depth_nr(root1));
                break;

            case 13:
                mirror_r(root1);
                printf("\nTree is mirrored: "); 
                inorder_r(root1);

                printf("\nTree is re-mirrored by nonrec: ");
                mirror_nr(root1);
                inorder_r(root1);
                break;


        }

        printf("\nContinue switch case? Enter 1 for yes: "); scanf("%d", &contswitch);

    }
    
    return 0;
 }