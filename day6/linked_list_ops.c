#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int prn;
    char name[20];
    struct node *next;
};

void add_in_list(struct node *head) {
    struct node *ptr;
    struct node *last;
    char cont = '\0';
    last = head;

    while (last->next != NULL)
        last = last->next;

    do {
        ptr = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter new PRN: ");
        scanf("%d", &(ptr->prn));
        printf("Enter member name: ");
        scanf("%s", ptr->name);
        ptr->next = NULL;
        last->next = ptr;
        last = ptr;

        printf("Add more members? (y for yes): ");
        scanf(" %c", &cont);
    } while (cont == 'Y' || cont == 'y');
}

void display_list(struct node *head) {
    struct node *temp = head->next;
    printf("\nMember Details:\n");
    while (temp != NULL) {
        printf("%d\t%s\n", temp->prn, temp->name);
        temp = temp->next;
    }
    printf("\n");
}

int length_linked(struct node *head) {
    struct node *temp = head->next;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void insert_member_at_position(struct node *head) {
    struct node *ptr, *temp;
    int position = 0, len = 0, count = 1;

    len = length_linked(head);
    ptr = (struct node *)malloc(sizeof(struct node));

    printf("Enter new member PRN: ");
    scanf("%d", &(ptr->prn));
    printf("Enter member name: ");
    scanf("%s", ptr->name);
    printf("Enter position: ");
    scanf("%d", &position);

    if (position > len + 1 || position <= 0) {
        printf("Invalid position!\n");
        free(ptr);
        return;
    }

    temp = head;
    while (count < position && temp->next != NULL) {
        count++;
        temp = temp->next;
    }

    ptr->next = temp->next;
    temp->next = ptr;
}

void delete_president(struct node *head) {
    if (head->next == NULL) {
        printf("List empty!\n");
        return;
    }

    struct node *temp = head->next;
    head->next = temp->next;
    free(temp);
    printf("President deleted successfully!\n");
}

void delete_secretory(struct node *head) {
    if (head->next == NULL) {
        printf("List empty!\n");
        return;
    }

    struct node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
    printf("Secretary deleted successfully!\n");
}

void delete_occurance_at_position(struct node *head) {
    if (head->next == NULL) {
        printf("List empty!\n");
        return;
    }

    int position, count = 1, len = length_linked(head);
    struct node *temp = head->next, *prev = head;

    printf("Enter position to delete: ");
    scanf("%d", &position);

    if (position > len || position <= 0) {
        printf("Invalid position!\n");
        return;
    }

    while (count < position && temp != NULL) {
        count++;
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp->next;
    free(temp);
    printf("Member deleted successfully!\n");
}

void reverse_list(struct node *head) {
    struct node *p = NULL, *q = head->next, *r;
    while (q != NULL) {
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    head->next = p;
    printf("List reversed successfully!\n");
}

void sort_list(struct node *head) {
    int len = length_linked(head);
    if (len < 2) return;

    struct node *prev, *curr, *temp;
    for (int i = 0; i < len - 1; i++) {
        prev = head;
        curr = head->next;
        while (curr->next != NULL) {
            temp = curr->next;
            if (curr->prn > temp->prn) {
                curr->next = temp->next;
                temp->next = curr;
                prev->next = temp;
                prev = temp;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
    }
    printf("List sorted successfully!\n");
}

void merge_lists(struct node *head1, struct node *head2) {
    struct node *t1 = head1->next, *t2 = head2->next;
    struct node *head3 = (struct node *)malloc(sizeof(struct node));
    struct node *t3 = head3;

    head3->next = NULL;

    while (t1 != NULL && t2 != NULL) {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        if (t1->prn < t2->prn) {
            newNode->prn = t1->prn;
            strcpy(newNode->name, t1->name);
            t1 = t1->next;
        } else {
            newNode->prn = t2->prn;
            strcpy(newNode->name, t2->name);
            t2 = t2->next;
        }
        newNode->next = NULL;
        t3->next = newNode;
        t3 = newNode;
    }

    while (t1 != NULL) {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->prn = t1->prn;
        strcpy(newNode->name, t1->name);
        newNode->next = NULL;
        t3->next = newNode;
        t3 = newNode;
        t1 = t1->next;
    }

    while (t2 != NULL) {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->prn = t2->prn;
        strcpy(newNode->name, t2->name);
        newNode->next = NULL;
        t3->next = newNode;
        t3 = newNode;
        t2 = t2->next;
    }

    printf("\nMerged list:\n");
    display_list(head3);
}

int main() {
    struct node *head, *head1;
    int choice = 0;
    char cont = '\0';

    head = (struct node *)malloc(sizeof(struct node));
    head->next = NULL;

    head1 = (struct node *)malloc(sizeof(struct node));
    head1->next = NULL;

    do {
        printf("\n---------- MENU ----------\n");
        printf("1. Add member\n2. Count members\n3. Display members\n4. Insert member\n");
        printf("5. Delete President\n6. Delete Secretary\n7. Delete by position\n");
        printf("8. Reverse list\n9. Sort list\n10. Merge two lists\n");
        printf("---------------------------\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_in_list(head); break;
            case 2: printf("Total members: %d\n", length_linked(head)); break;
            case 3: display_list(head); break;
            case 4: insert_member_at_position(head); break;
            case 5: delete_president(head); break;
            case 6: delete_secretory(head); break;
            case 7: delete_occurance_at_position(head); break;
            case 8: reverse_list(head); break;
            case 9: sort_list(head); break;
            case 10:
                printf("\nEnter data for 2nd list:\n");
                add_in_list(head1);
                sort_list(head);
                sort_list(head1);
                merge_lists(head, head1);
                break;
            default: printf("Invalid choice!\n");
        }

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &cont);

    } while (cont == 'Y' || cont == 'y');

    printf("Exited.\n");
    return 0;
}
