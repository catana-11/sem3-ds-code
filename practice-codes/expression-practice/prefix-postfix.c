#include <stdio.h>
#include <string.h>


char stack[20][20];
int top = -1;

void push(char temp[10]){
    top++;
    strcpy(stack[top], temp);
}

void pop(char temp[10]){
    strcpy(temp, stack[top]);
    top--;
}

//--------------------------------------------------------

void prefix_infix(char prefix[20], char postfix[20]){

    int i=0; 


    char top1[10] = {'\0'};
    char top2[10] = {'\0'};

    strrev(prefix);

    while(prefix[i]!='\0'){

        // case 1: if incoming is operator:
        if (prefix[i]=='+' || prefix[i]=='-' || prefix[i]=='*' || prefix[i]=='/'){

            pop(top1); pop(top2);

            char temp[20] = {'\0'};

            char operator[2] = {prefix[i], '\0'};

    
            strcpy(temp, top1);
            strcat(temp, top2);
            strcat(temp, operator);
 

            push(temp);

        }

        else{
            char temp[2] = {prefix[i], '\0'};
            push(temp);
        }

        i++;

    }

    pop(postfix);

}

//--------------------------------------------------------
int main(){

    char prefix[20]; char postfix[20];

    printf("\nEnter your prefix string: "); scanf("%s", prefix);

    prefix_infix(prefix, postfix);
    printf("\nPostfix is: %s", postfix);

    return 0;
}