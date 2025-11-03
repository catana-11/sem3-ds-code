#include <stdio.h>
#include <string.h>

// stack ---->

char stack[20]; 
int top = -1;

void push(char temp){
    top++;
    stack[top] = temp;
}

void pop(char *temp){
    *temp = stack[top];
    top--;
}

// icp isp -->

int isp(char op){

    if (op == ')') return 0;
    else if (op == '+' || op == '-') return 1;
    else if (op == '*' || op == '/') return 2;
    else if (op == '^') return 3;
    else return -1;
}


int icp(char op){

    if (op == ')') return 5;
    else if (op == '+' || op == '-') return 1;
    else if (op == '*' || op == '/') return 2;
    else if (op == '^') return 4;
    else return -1;
}

// infix to prefix -->

void infix_to_prefix(char infix[20], char prefix[20]){

    int i=0, k = -1;

    strrev(infix);
    printf("\nReversed infix string: %s", infix);

    while(infix[i]!='\0'){

        // case 1 --> closing bracket --> just push in stack

        if (infix[i] == ')') push(infix[i]);

        // case 2 --> if opening bracket ---> pop until closing bracket and append in prefix string

        else if (infix[i] == '('){
            char temp;

            while(stack[top]!=')'){
                pop(&temp);
                k++;
                prefix[k] = temp;
            }

            pop(&temp); // the closing bracket
        }

        // case 3  --> normal operator:

        else if (infix[i] == '+' || infix[i] == '-'|| infix[i] == '*'|| infix[i] == '/'){

            char temp;

            while(top>=0 && icp(infix[i]) <= isp(stack[top])){
                pop(&temp);
                k++;
                prefix[k] = temp;
            }

            push(infix[i]);
        }

        // case 4 --> variable

        else{
            k++;
            prefix[k] = infix[i];
        }

        i++;

    
    }
    char temp;
    while(top>=0) {
        // pop contents into answer
        pop(&temp);
        k++;
        prefix[k] = temp;
    }
    k++;
    prefix[k] = '\0';

    strrev(prefix);

}

int main(){
    char infix[20]; char prefix[20] = {'\0'};

    printf("\nEnter the infix string: "); scanf("%s", infix);

    infix_to_prefix(infix, prefix);

    printf("\nThe prefix answer string is: %s", prefix);

    return 0;
}