#include <stdio.h>
#include <string.h>

// stack -->
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

// postfix to prefix -->

void postfix_to_prefix(char postfix[20], char prefix[20]){

    int i=0;
    char top1[20] = {'\0'};
    char top2[20] = {'\0'};

    while(postfix[i]!='\0'){

        if (postfix[i] == '+' || postfix[i] == '-' ||postfix[i] == '*' ||postfix[i] == '/'){

            pop(top1); pop(top2);

            char operator[2] = {postfix[i], '\0'};

            char temp[20] = {'\0'};

            strcat(temp,operator);
            strcat(temp,top2);
            strcat(temp,top1);

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

int main(){

    char prefix[20]= {'\0'}; char postfix[20]= {'\0'};

    printf("\nEnter postfix string: "); scanf("%s", postfix);

    postfix_to_prefix(postfix, prefix);

    printf("\nThe prefix string is: %s", prefix);

    return 0;
}