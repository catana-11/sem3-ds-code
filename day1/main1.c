/******************************************************************************
program:
accept two numbers from the users and perform operation:
+, -, *, /
*******************************************************************************/
#include <stdio.h>

void addition(int a, int b)
{
    printf("The addition is: %d \n", a+b);
}

void subtraction(int a, int b)
{
    printf("The subtraction is: %d \n", a-b);
}

void mul(int a, int b)
{
    printf("The multiplication is: %d \n", a*b);
}

void division(int a, int b)
{
    printf("The division is: %d \n", a/b);
}

int main()
{   
    int a, b, choice, repeat, r;
    repeat = 1; r=0;
    
while (repeat == 1) {
    
    printf("Menu: \n1. Addition\n2. Subtraction \n3. Multiplication \n4. Division");
    printf("\nEnter your choice: "); scanf("%d", &choice);
    
    printf("\nEnter first number: "); scanf("%d", &a);    
    printf("\nEnter second number: "); scanf("%d", &b);

    switch (choice) {
        case 1:
        addition(a, b);
        break;
        
        case 2:
        subtraction(a,b);
        break;
        
        case 3:
        mul(a,b);
        break;
        
        case 4:
        division(a,b);
        break;
        
        default:
        printf("Wrong choice.");
    }
    
    repeat = 0;
    printf("Continue? Enter 1: "); scanf("%d", &repeat);
}
    
    return 0;
}