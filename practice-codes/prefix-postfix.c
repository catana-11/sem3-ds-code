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

// prefix - postfix -->

void prefix_to_postfix(char prefix[20], char postfix[20]){

    int i=0;
    char top1[20] = {'\0'};
    char top2[20] = {'\0'};

    strrev(prefix);
    

    while(prefix[i]!='\0'){

        if (prefix[i] == '+' || prefix[i] == '-' ||prefix[i] == '*' ||prefix[i] == '/'){
            pop(top1); pop(top2);

            char operator[2] = {prefix[i], '\0'};

            char temp[20] = {'\0'};

            strcpy(temp,top1);
            strcat(temp,top2);
            strcat(temp,operator);

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

int main(){

    char prefix[20]= {'\0'}; char postfix[20]= {'\0'};

    printf("\nEnter prefix string: "); scanf("%s", prefix);

    prefix_to_postfix(prefix, postfix);

    printf("\nThe postfix string is: %s", postfix);

    return 0;
}