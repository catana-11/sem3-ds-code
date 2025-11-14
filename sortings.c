#include <stdio.h>

struct student{
    int marks;
    int prn;
};



void bubble(int n, struct student s[n]){
    for (int i=0; i<n; i++){
        int swapped = 0; struct student temp;

        for (int j=0; j<n-1; j++){
            if (s[j].marks> s[j+1].marks){
                temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
                swapped = 1;
            }
        }
    }
}

void selection(int n, struct student s[n]){

    int min_index;
    for (int i=0; i<n; i++){
        min_index = i;

        for(int j=i+1; j<n; j++){
            if (s[j].marks<s[min_index].marks){
                min_index = j;
            }
        }

        if(min_index!=i){
            struct student temp;
            temp = s[i];
            s[i] = s[min_index];
            s[min_index] = temp;
        }

    }
}

void insertion(int n, struct student s[n]){

    struct student key; int j;
    for (int i=0; i<n; i++){
        key = s[i]; j = i-1;

        while(j>=0 && s[j].marks>key.marks){
            s[j+1]= s[j];
            j--;
        }

        s[j+1] = key;

    }
}



int main(){

    int n; 

    printf("\nEnter the number of elems for aray: "); scanf("%d", &n);

    struct student s[n];

    for (int i=0; i<n; i++){
        printf("\nEnter prn %d: ", i); scanf("%d", &s[i].prn);
        printf("\nEnter marks %d: ", i); scanf("%d", &s[i].marks);
    }

    int choice = 0;

    printf("\nEnter choice: "); scanf("%d", &choice);

    if (choice==0){
    bubble(n, s);
    for (int i=0; i<n; i++){
        printf("[%d, %d], ", s[i].prn, s[i].marks);
    }
    }   

    if (choice==1){
    selection(n, s);
    for (int i=0; i<n; i++){
        printf("[%d, %d], ", s[i].prn, s[i].marks);
    }  
    }


    if (choice==2){
    insertion(n, s);
    for (int i=0; i<n; i++){
        printf("[%d, %d], ", s[i].prn, s[i].marks);
    }  
    }

    return 0;
}