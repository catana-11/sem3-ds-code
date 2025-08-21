/****************************************************************************** 
Sorting Program:
take: roll no, name, marks, division.
sorting using:
1. bubble sort -> roll no (asc)
2. bubble sort -> name (asc)
3. selection sort -> marks (desc)
4. insertion sort -> name (desc
*******************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct student {
    int marks;
    char name[20];
    int rollno;
    char division[20];
};

// fn to read struct 
void read_struct(int n, struct student e[n]) {
    for (int i = 0; i < n; i++) {
        printf("Entry #%d:\n", i + 1);
        printf("Enter Marks: "); scanf("%d", &e[i].marks);
        printf("Enter Name: ");  scanf("%s", e[i].name);
        printf("Enter Roll No: "); scanf("%d", &e[i].rollno);
        printf("Enter Division: "); scanf("%s", e[i].division);
        printf("\n");
    }
}


void show_struct(int n, struct student e[n]) {
    printf("\n%-8s %-20s %-10s %-10s\n", "Marks", "Name", "Roll No", "Division");
    printf("-----------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("%-8d %-20s %-10d %-10s\n", e[i].marks, e[i].name, e[i].rollno, e[i].division);
    }
}

// bubble sort by rollno (asc)
void bubble_sort_roll(int n, struct student e[n]) {
    struct student temp;
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (e[j].rollno > e[j + 1].rollno) {
                temp = e[j];
                e[j] = e[j + 1];
                e[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break;
    }

    printf("\nBubble Sort by rollno (asc):\n");
    show_struct(n, e);
}

// nubble sort by name (asc)
void bubble_sort_name_asc(int n, struct student e[n]) {
    struct student temp;
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(e[j].name, e[j + 1].name) > 0) {
                temp = e[j];
                e[j] = e[j + 1];
                e[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break;
    }

    printf("\nBubble Sort by name (asc):\n");
    show_struct(n, e);
}

// selection sort by marks (desc)
void selection_sort_marks_desc(int n, struct student e[n]) {
    struct student temp;
    for (int i = 0; i < n - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (e[j].marks > e[max_idx].marks) {
                max_idx = j;
            }
        }
        if (max_idx != i) {
            temp = e[i];
            e[i] = e[max_idx];
            e[max_idx] = temp;
        }
    }

    printf("\nSelection Sort by marks (desc):\n");
    show_struct(n, e);
}

// Insertion sort by name (desc)
void insertion_sort_name_desc(int n, struct student e[n]) {
    for (int i = 1; i < n; i++) {
        struct student key = e[i];
        int j = i - 1;

        while (j >= 0 && strcmp(e[j].name, key.name) < 0) {
            e[j + 1] = e[j];
            j--;
        }
        e[j + 1] = key;
    }

    printf("\nInsertion Sort by name (desc):\n");
    show_struct(n, e);
}

int main() {
    int n, choice, go = 1;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct student e[n];
    read_struct(n, e);

    printf("\nog data:\n");
    show_struct(n, e);

    while (go == 1) {
        printf("\nMenu:\n");
        printf("1. Bubble Sort by roll no. (asc)\n");
        printf("2. Bubble Sort by name (asc)\n");
        printf("3. Selection Sort by marks (desc)\n");
        printf("4. Insertion Sort by name (desc)\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bubble_sort_roll(n, e);
                break;
            case 2:
                bubble_sort_name_asc(n, e);
                break;
            case 3:
                selection_sort_marks_desc(n, e);
                break;
            case 4:
                insertion_sort_name_desc(n, e);
                break;
            default:
                printf("Invalid choice.\n");
        }

        printf("\nContinue? Type 1 for yes: ");
        scanf("%d", &go);
    }

    return 0;
}