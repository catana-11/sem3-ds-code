/******************************************************************************
program:
accept information in structure, using functions 
*******************************************************************************/

#include <stdio.h>

struct emp {
        int id;
        char name[20];
        int rollno;
        char course[20];
    };

void read_struct(int p, struct emp e[p]){ // pass the size, struct declaration AND size in it
    
    int i=0;
    for (i=0; i<p; i++){
            printf("Enter id: "); scanf("%d", &e[i].id );
            printf("Enter name: "); scanf("%s", &e[i].name );
            printf("Enter rollno: "); scanf("%d", &e[i].rollno );
            printf("Enter course name: "); scanf("%s", &e[i].course);
            printf("\n");}
}

void show_struct(int p, struct emp e[p]){

    int i=0;
    printf("\nThe entries of struct are: \n");
    printf("id \t name \t rollno \t course \n");
        for (i=0; i<p; i++){
            printf(" %d\t", e[i].id); 
            printf(" %s\t", e[i].name);
            printf(" %d\t", e[i].rollno);
            printf(" %s\t", e[i].course);
            printf("\n");}
}

int main() {
    
    int p=0, i=0;

    printf("Enter the number of entries needed: "); scanf("%d", &p);
    struct emp e[p];
        read_struct(p,e);
        show_struct(p,e); 
}