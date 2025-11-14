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

void prefix_infix(char prefix[20], char infix[20]){

    int i=0; 
    char bracketop[2] = {'(', '\0'};
    char bracketcl[2] = {')', '\0'};

    char top1[10] = {'\0'};
    char top2[10] = {'\0'};

    strrev(prefix);

    while(prefix[i]!='\0'){

        // case 1: if incoming is operator:
        if (prefix[i]=='+' || prefix[i]=='-' || prefix[i]=='*' || prefix[i]=='/'){

            pop(top1); pop(top2);

            char temp[20] = {'\0'};

            char operator[2] = {prefix[i], '\0'};

            strcpy(temp, bracketop);
            strcat(temp, top1);
            strcat(temp, operator);
            strcat(temp, top2);
            strcat(temp, bracketcl);

            push(temp);

        }

        else{
            char temp[2] = {prefix[i], '\0'};
            push(temp);
        }

        i++;

    }

    pop(infix);

}

//--------------------------------------------------------
int main(){

    char prefix[20]; char infix[20];

    printf("\nEnter your prefix string: "); scanf("%s", prefix);

    prefix_infix(prefix, infix);
    printf("\nInfix is: %s", infix);

    return 0;
}