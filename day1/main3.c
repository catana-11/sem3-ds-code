/******************************************************************************
program:
accept information in structure format, using functions, and perform sorting (bubble on id)
*******************************************************************************/

#include <stdio.h>
#include <stdbool.h>

struct emp {
        int id;
        char name[20];
        int rollno;
        char course[20];
    };

void read_struct(int p, struct emp e[p]){
    
    int i=0;
    
    for (i=0; i<p; i++){
            printf("Enter id: "); scanf("%d", &e[i].id );
            printf("Enter name: "); scanf("%s", &e[i].name );
            printf("Enter rollno: "); scanf("%d", &e[i].rollno );
            printf("Enter course name: "); scanf("%s", &e[i].course);
            printf("\n");}  
}

void show_struct(int n, struct emp e[n]) {
    printf("\n%-5s %-20s %-10s %-20s\n", "ID", "Name", "Roll No", "Course");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-5d %-20s %-10d %-20s\n", e[i].id, e[i].name, e[i].rollno, e[i].course);
    }
}


int main() {
    
    int p=0, i=0, j=0;
    
    
    printf("Enter the number of entries needed: "); scanf("%d", &p);
    struct emp e[p];

    read_struct(p, e);
    show_struct(p,e);
        
        // now bubble sorting the struct
        // e.id is an array, elements given by e[i].id
    struct emp temp[p];         // a temp variable just as same as the og structure
    for (i=0; i<p; i++){
        
        bool swapped;
        swapped = false;
        
        for (j=0; j<p-i-1; j++){

            if (e[j].id > e[j+1].id) {

                temp[j] = e[j];
                e[j] = e[j+1];
                e[j+1] = temp[j];}      // switched the whole rows in original

            swapped = true;
        }
        
        if (swapped == false) {break;}
    }
    
    printf("\nBubble sorted struct:");
    show_struct(p,e);
      
    
}
