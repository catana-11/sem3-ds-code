#include <stdio.h>
#include <string.h>
// AB+CD-* -->((A+B)*(C-D))

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

void postfix_infix(char postfix[20], char infix[20]){

    int i=0; 
    char bracketop[2] = {'(', '\0'};
    char bracketcl[2] = {')', '\0'};

    char top1[10] = {'\0'};
    char top2[10] = {'\0'};

    while(postfix[i]!='\0'){

        // case 1: if incoming is operator:
        if (postfix[i]=='+' || postfix[i]=='-' || postfix[i]=='*' || postfix[i]=='/'){

            pop(top1); pop(top2);

            char temp[20] = {'\0'};

            char operator[2] = {postfix[i], '\0'};

            strcpy(temp, bracketop);
            strcat(temp, top2);
            strcat(temp, operator);
            strcat(temp, top1);
            strcat(temp, bracketcl);

            push(temp);

        }

        else{
            char temp[2] = {postfix[i], '\0'};
            push(temp);
        }

        i++;

    }

    pop(infix);

}

//--------------------------------------------------------
int main(){

    char postfix[20]; char infix[20];

    printf("\nEnter your postfix string: "); scanf("%s", postfix);

    postfix_infix(postfix, infix);
    printf("\nInfix is: %s", infix);

    return 0;
}