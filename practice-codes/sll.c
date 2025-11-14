#include <stdio.h>
#include <stdlib.h>

struct node {
    int rno;
    struct node *next;
};

void create_sll(struct node *head){

    struct node *ptr, *last;
    last = head;
    int cont = 1;

    while(cont == 1){
        
        ptr = (struct node*)malloc(sizeof(struct node*));
        ptr->next = NULL;

        printf("\nEnter the new roll number: "); scanf("%d", &ptr->rno);

        last->next = ptr;
        last = last->next;

        printf("\nDo you want to continue entering data? Enter 1 for yes: "); scanf("%d", &cont);
    }
}

void display_sll(struct node *head){

    struct node *temp;
    temp = head->next;

    while(temp!=NULL){
        printf("%d -->   ", temp->rno);
        temp = temp->next;
    }
}

int length_sll(struct node *head){
    struct node *temp;
    temp = head->next;
    int counter = 0;

    if (temp == NULL) {return 0;} // only head condition

    while(temp!=NULL){
        counter +=1;
        temp = temp->next;
    }

    return counter;
}

void insert_at_pos(struct node *head){
    struct node *prev, *ptr;
    prev = head;

    int pos = 0, counter = 0;

    printf("\nEnter the position of node to insert (consider first node is 0): "); scanf("%d", &pos);

    while(prev!=NULL && counter<pos){

        prev = prev->next;
        counter++;
        if (prev==NULL) {printf("\nInvalid position!"); return;}
        
    }

    ptr = (struct node*)malloc(sizeof(struct node*));
    ptr->next = NULL;

    printf("\nEnter the roll number: "); scanf("%d", &ptr->rno);

    ptr->next = prev->next;
    prev->next = ptr;

    display_sll(head);

}

void delete_at_pos(struct node *head){
    struct node *prev, *curr;
    prev = head;
    curr = prev->next;

    int pos = 0, counter = 0;

    if (head->next == NULL){printf("\nNo nodes to delete."); return;}

    printf("\nEnter the position of node to delete (consider first node is 0): "); scanf("%d", &pos);

    while(curr!=NULL && counter<pos){

        prev = prev->next;
        curr = curr ->next;
        counter++;
        if (prev==NULL) {printf("\nInvalid position!"); return;}
        if (curr == NULL) {printf("\nInvalid position!"); return;}
        
    }

    prev->next = curr->next;
    curr->next = NULL;
    free(curr);
    display_sll(head);

}

void reverse_sll(struct node *head){
    struct node *prev, *curr, *next;
    prev = next = NULL;
    curr = head->next;

    while (curr!=NULL){
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }

    head->next = prev;

    display_sll(head);
}

void sort_sll(struct node *head){

    struct node *temp, *curr;
    curr = temp = head;

    int swapped = 1;

    while(swapped){
        curr = head;
        swapped = 0;

        while(curr->next!=NULL){

            if (curr->rno >curr->next->rno){
                temp->rno = curr->rno;
                curr->rno = curr->next->rno;
                curr->next->rno = temp->rno;

                swapped = 1;
            }

            curr = curr->next;
        }
    }

    display_sll(head);

}

struct node *merge_sll(struct node *head1, struct node *head2){

    struct node *t1, *t2, *t3, *head3,*ptr;

    head3 = (struct node*)malloc(sizeof(struct node*));
    head3->rno = 0; head3->next = NULL;
    t1 = head1->next; t2= head2->next; t3 = head3;

    while(t1!=NULL && t2!=NULL){

        if (t1->rno<t2->rno){
            ptr = (struct node*)malloc(sizeof(struct node*));
            ptr->rno = t1->rno; ptr->next = NULL;
            t3->next = ptr;
            t3 = t3->next;
            t1 = t1->next;
        }

        else{
            ptr = (struct node*)malloc(sizeof(struct node*));
            ptr->rno = t2->rno; ptr->next = NULL;
            t2 = t2->next;
            t3->next = ptr;
            t3 = t3->next;
        }

        
    }

    while(t1!=NULL){
            ptr = (struct node*)malloc(sizeof(struct node*));
            ptr->rno = t1->rno; ptr->next = NULL;
            t3->next = ptr;
            t3 = t3->next;
            t1 = t1->next;
        }

    while(t2!=NULL){
        ptr = (struct node*)malloc(sizeof(struct node*));
        ptr->rno = t2->rno; ptr->next = NULL;
        t3->next = ptr;
        t3 = t3->next;
        t2 = t2->next;
    }

    return head3;

}

int main(){

    struct node *head;
    struct node *head2, *head3;
    head = (struct node*)malloc(sizeof(struct node*));
    head->rno = 0;
    head->next = NULL;

    int x; int cont = 1;

    while(cont == 1){
        printf("\n-------MENU-------\n1. Create SLL\n2. Display SLL\n3. Insert at position\n4. Length of SLL\n5. Delete at position\n6. Reverse\n7. Bubble sort\n8. Merge");
        printf("\nEnter your choice of option: "); scanf("%d", &x);

        switch (x){
            case 1:
                create_sll(head);
                break;
            case 2:
                display_sll(head);
                break;
            
            case 3:
                insert_at_pos(head);
                break;

            case 4:
                printf("\nThe length of SLL is: %d", length_sll(head));
                break;

            case 5:
                delete_at_pos(head);
                printf("delete done");
                break;
            
            case 6:
                reverse_sll(head);
                break;

            case 7:
                sort_sll(head);
                break;

            case 8:
                
                head2 = (struct node*)malloc(sizeof(struct node*));
                create_sll(head2);

                head3 = merge_sll(head, head2);
                display_sll(head3);
                break;


        }

        printf("\nDo you want to continue the program? Enter 1: "); scanf("%d", &cont);
    }

    return 0;
}

