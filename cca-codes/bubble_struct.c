#include <stdio.h>

struct stud{

    int rollno;
    char name[20];
    int marks;
};

void bubble_sort(int s, struct stud student[s]){


    int swapped = 0;
    struct stud temp[s];

    for (int i=0; i<s; i++){
        swapped = 0;
        for (int j=0; j<s-i-1; j++){

            if (student[j].marks> student[j+1].marks) {
                temp[j] = student[j+1];
                student[j+1] = student[j];
                student[j] = temp[j];

                swapped = 1;
            }
        
        if (swapped = 0) {break;}

        }
      
    }
    
    printf("\nThe sorted struct is: \n");

    for (int i=0; i<s; i++){
        printf("%d  ", student[i].rollno);
        printf("%s  ", student[i].name);
        printf("%d  ", student[i].marks);
    printf("\n"); }
        

}

void main() {


    
    int a = 0;
    printf("Enter the struct size: "); scanf("%d", &a); 

    struct stud student[a];
    
    for (int i=0; i<a; i++){
        printf("Enter roll no.: ", i); scanf("%d", &student[i].rollno);
        printf("Enter name: ", i); scanf("%s", &student[i].name);
        printf("Enter marks: ", i); scanf("%d", &student[i].marks);
    }

    printf("The struct is: \n");

    for (int i=0; i<a; i++){
        printf("%d  ", student[i].rollno);
        printf("%s  ", student[i].name);
        printf("%d  ", student[i].marks); 
        printf("\n");
    }

    // bubble sorting the student: 
    bubble_sort(a, student);


}