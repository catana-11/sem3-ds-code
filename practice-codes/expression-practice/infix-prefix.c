#include <stdio.h>
#include <string.h>

int isp(char ch){
    if (ch=='+' ||ch=='-') return 1;
    else if (ch=='*' ||ch=='/') return 2;
    else if (ch=='^') return 3;
    else if (ch==')') return 0;
    else return -1;

}

int icp(char ch){
    if (ch=='+' ||ch=='-') return 1;
    else if (ch=='*' ||ch=='/') return 2;
    else if (ch=='^') return 4;
    else if (ch==')') return 5;
    else return -1;

}

char stack[20];
int top = -1;

void push(char ch){
    top++;
    stack[top] = ch;

}

void pop(char *op){
    *op = stack[top];
    top--;
}

void infix_prefix(char infix[20], char prefix[20]){

    int i=0; int k = -1;
    strrev(infix);
    

    while(infix[i]!='\0'){

        //case 1: (, push in stack
        if (infix[i] == ')') push(infix[i]);

        // case 2: ), pop till (
        else if (infix[i]=='('){
            char temp;
            while(top>=0 && stack[top]!=')'){
        
                pop(&temp);
                k++;
                prefix[k] = temp;
            }

            pop(&temp);

        }

        // case 3: an operator:
        else if(infix[i]=='+' || infix[i]=='-' ||infix[i]=='*' ||infix[i]=='/'){
            char temp;
            while(top>=0 && icp(infix[i])<= isp(stack[top])){
                pop(&temp);
                k++; prefix[k] = temp;

            }

            push(infix[i]);
        }
        
        //case 4: character:
        else{
            k++;
            prefix[k] = infix[i];
        }

        i++;
    }

    while(top>=0){
        char temp;
        pop(&temp);
        k++; prefix[k] = temp;
    }

    k++; prefix[k]='\0';

    strrev(prefix);

}

int main(){

    char infix[20]; char prefix[20];
    printf("\nEnter infix string: "); scanf("%s", infix);

    infix_prefix(infix, prefix);
    printf("\nprefix string is: %s", prefix);


    return 0;
}