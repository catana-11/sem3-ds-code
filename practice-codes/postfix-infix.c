#include <stdio.h>
#include <string.h>

// stack --->
char stack[20][20];
int top = -1;

void push(char temp[20]){
    top++;
    strcpy(stack[top], temp);
}

void pop(char temp[20]){
    strcpy(temp, stack[top]);
    top--;
}

// postfix-infix ---->

void postfix_to_infix(char postfix[20], char infix[20]){

    int i=0;

    char top1[20] = {'\0'};
    char top2[20] = {'\0'};

    char operator[2] = {'+', '\0'};
    char bracket1[2] = {'(', '\0'};
    char bracket2[2] = {')', '\0'};

    while(postfix[i]!='\0'){

        if (postfix[i] == '+'|| postfix[i] == '-'|| postfix[i] == '*'|| postfix[i] == '/'){
            pop(top1); pop(top2);

            operator[0] = postfix[i];

            char temp[20] = {'\0'};

            strcpy(temp, bracket1);
            strcat(temp, top2);
            strcat(temp, operator);
            strcat(temp, top1);
            strcat(temp, bracket2);

            push(temp);
        }

        else{
            char temp[2] = {postfix[i],'\0'};
            push(temp);
        }
        i++;   
    }
    pop(infix);
}

int main(){

    char infix[20] = {'\0'}; char postfix[20] = {'\0'};

    printf("\nEnter postfix string: "); scanf("%s", postfix);
    
    postfix_to_infix(postfix, infix);

    printf("\nThe infix string is: %s", infix);

    return 0;
}