#include <stdio.h>
#include <stdlib.h>

struct node{
   int data;
   struct node *left;
   struct node *right;
   int lbit;
   int rbit;
};

struct node *head, *root;

void tbt_create(){

   head = (struct node *)malloc(sizeof(struct node));
   head->data = 0;
   root = (struct node *)malloc(sizeof(struct node));

   printf("\nEnter root data: "); scanf("%d", &root->data);

   head->left = root; head->right=head;
   head->lbit = 1; head->rbit= 1;

   root->lbit = 0; root->rbit = 0;
   root->left = head; root->right = head;

   //----------------------------------------------------
   char choice  ='l';
   int cont = 0;
   struct node *temp;
   temp = (struct node *)malloc(sizeof(struct node));

   do{
       struct node *ptr, *prev;
       int flag = 0;
       temp = root;
       ptr = (struct node *)malloc(sizeof(struct node));
       prev = (struct node *)malloc(sizeof(struct node));
       prev = head;

       printf("\nEnter new node data: "); scanf("%d", &ptr->data);
       ptr->lbit = ptr->rbit = 0;

       while(flag == 0){
           printf("\nAttach new node to l/r of %d?: ", temp->data); scanf(" %c", &choice);

           if (choice=='l'){
               if (temp->lbit ==0){
                   temp->left = ptr;
                   temp->lbit = 1;
                   ptr->lbit = 0; ptr->rbit = 0;
                   ptr->right = temp;
                   ptr->left = prev;
                   flag = 1;
               }
               else{
                   prev = temp;
                   temp = temp->left;
                   flag = 0;
               }
           }
           if (choice=='r'){
               if (temp->rbit ==0){
                   temp->right= ptr;
                   temp->rbit = 1;
                   ptr->lbit = 0; ptr->rbit = 0;
                   ptr->left = temp;
                   ptr->right = prev;
                   flag = 1;
               }
               else{
                   prev = temp;
                   temp = temp->right;
                   flag = 0;
               }
           }
       }
       printf("\nDo you want to continue? Enter 1: "); scanf("%d",&cont);

   } while(cont == 1);

}

struct node *inorder_successor(struct node *temp){

   struct node *x;
   x = temp->right;

   if (temp->rbit == 1){
       while(x->lbit==1){
           x = x->left;
       }
   }

   return x;
}


void tbt_traversal_inorder(){
   struct node *temp;
   temp = (struct node *)malloc(sizeof(struct node));
   temp = head;

   while(1){
       temp = inorder_successor(temp);
       if (temp==head){
           break;
       }
       else{
           printf("[%d]  ", temp->data);
       }   
   }
}

void pre_order(){
  
   struct node *temp;
   temp = head->left;

   while(temp!=head){

       printf("[%d]    ", temp->data);

       while(temp->lbit ==1){
           temp = temp->left;
           printf("[%d]    ", temp->data);
       }

       while(temp->rbit == 0){
           temp = temp->right;}

        temp = temp->right;
       }
   }



void tbt_postorder() {
    struct node *stack[50];
    int top = -1;

    struct node *temp = head->left;   // root
    struct node *lastVisited = NULL;

    while (top != -1 || temp != head) {
        // push all real left children
        if (temp != head && temp->lbit == 1) {
            stack[++top] = temp;
            temp = temp->left;
        } 
        else {
            // peek the node on top of stack
            struct node *peek = stack[top];

            // if right child exists and not visited yet
            if (peek->rbit == 1 && peek->right != lastVisited) {
                temp = peek->right;
            } 
            else {
                printf("[%d]  ", peek->data);
                lastVisited = peek;
                top--; // pop
                temp = head; // reset temp
            }
        }
    }
}




int main(){

   printf("\nCalling create tbt...\n");
   tbt_create();

   printf("\nCalling tbt inorder traversal...\n");
   tbt_traversal_inorder();

   printf("\nCalling tbt preorder traversal...\n");
   pre_order();

   printf("\nCalling tbt postorder traversal...\n");
   tbt_postorder();

   return 0;
}
