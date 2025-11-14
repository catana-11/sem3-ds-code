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

void postfix_prefix(char postfix[20], char prefix[20]){

    int i=0; 


    char top1[10] = {'\0'};
    char top2[10] = {'\0'};

 
    while(postfix[i]!='\0'){

        // case 1: if incoming is operator:
        if (postfix[i]=='+' || postfix[i]=='-' || postfix[i]=='*' || postfix[i]=='/'){

            pop(top1); pop(top2);

            char temp[20] = {'\0'};

            char operator[2] = {postfix[i], '\0'};

            strcpy(temp, operator);
            strcat(temp, top2);
            strcat(temp, top1);
            

            push(temp);

        }

        else{
            char temp[2] = {postfix[i], '\0'};
            push(temp);
        }

        i++;

    }

    pop(prefix);

}

//--------------------------------------------------------
int main(){

    char postfix[20]; char prefix[20];

    printf("\nEnter your postfix string: "); scanf("%s", postfix);

    postfix_prefix(postfix, prefix);
    printf("\nPrefix is: %s", prefix);

    return 0;
}