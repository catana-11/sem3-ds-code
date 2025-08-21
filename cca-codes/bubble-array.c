#include <stdio.h>

void bubble_sort(int s, int arr[s]){
    int temp = 0; int swapped = 0;

    for (int i=0; i<s; i++){
        swapped = 0;
        for (int j=0; j<s-i-1; j++){

            if (arr[j]> arr[j+1]) {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;

                swapped = 1;
            }
        
        if (swapped = 0) {break;}

        }


      
    }
    printf("\nThe sorted array is: ");

    for (int i=0; i<s; i++){
        printf("%d  ", arr[i]); }

}

void main() {

    int a = 0;
    printf("Enter the array size: "); scanf("%d", &a); 

    int arr[a];

    for (int i=0; i<a; i++){
        printf("Enter %dth element: ", i); scanf("%d", &arr[i]);
    }

    printf("The array is: ");

    for (int i=0; i<a; i++){
        printf("%d  ", arr[i]); }

    // bubble sorting the array: 
    bubble_sort(a, arr);


}