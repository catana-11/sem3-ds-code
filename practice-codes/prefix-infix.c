#include <stdio.h>
#include <string.h>

// stack ops --->

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

// prefix-infix --->

void prefix_to_infix(char prefix[20], char infix[20]){

    char top1[20] ={'\0'};
    char top2[20] = {'\0'};

    char bracket1[2] = {'(', '\0'};
    char bracket2[2] = {')', '\0'};
 
    strrev(prefix);

    int i=0;

    while(prefix[i]!='\0'){

        if ( prefix[i] == '+' ||prefix[i] == '-' ||prefix[i] == '*' ||prefix[i] == '/'){

            // pop last two values
            pop(top1); pop(top2);
            char operator[2] = {prefix[i], '\0'};

            char temp[20] = {'\0'};

            strcpy(temp, bracket1);
            strcat(temp, top1);
            strcat(temp, operator);
            strcat(temp, top2);
            strcat(temp, bracket2);

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

int main(){

    char prefix[20];
    char infix[20] = {'\0'};

    printf("\nEnter prefix string: "); scanf("%s", prefix);

    prefix_to_infix(prefix, infix);

    printf("\nThe infix string is: %s", infix);

    return 0;
}