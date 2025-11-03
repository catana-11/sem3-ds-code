#include <stdio.h>

//infix to postfix

// stack operations-------------------->

char stack[20]; 
int top = -1;

void push(char op){
    top++;
    stack[top] = op;
}

void pop(char *op){
    // takes a variable, and puts the stack top in it
    *op = stack[top];
    top--;
}

// operator precedence functions ------->

int isp(char x){ // in stack operator

    if (x=='+'|| x=='-') return 1;
    else if (x=='*' || x=='/') return 2;
    else if (x=='^') return 3;
    else if (x=='(') return 0;
    else return -1;

}

int icp(char x){ // incoming operator

    if (x=='+'|| x=='-') return 1;
    else if (x=='*' || x=='/') return 2;
    else if (x=='^') return 4;
    else if (x=='(') return 5;
    else return -1;

}

// infix to postfix function ----->

void infix_to_postfix(char infix[20], char postfix[20]){

    int i = 0, k=-1;

    while (infix[i]!='\0'){

        // case 1 --> incoming character is opening bracket
        // solution --> push in stack

        if (infix[i] == '(') push(infix[i]);

        // case 2 --> incoming character is a closing bracket
        // solution --> pop stack till ( is found and push the popped characters in answer string

        else if (infix[i] == ')'){
            
            char temp;

            while (stack[top]!='('){
                pop(&temp);
    
                k++;
                postfix[k] = temp;
            }
            pop(&temp); // just to remove the ) from the stack
        }
        
        // case 3 --> other operator
        else if(infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^'){
            
            // if incoming character is small, pop , and keep popping till stack char >=incoming
            char temp;

            while(top>=0 && icp(infix[i]) <= isp(stack[top])){

                pop(&temp);
                k++;
                postfix[k] = temp;
            }

            push(infix[i]);
        }

        // case 4 --> character ; solution --> push it in string

        else{
            k++;
            postfix[k] = infix[i];
        }
        
        i++;
    }

    // pop the remaining stack
    char temp;
    while(top>=0){
        pop(&temp);
        k++;
        postfix[k] = temp;
    }

    k++;
    postfix[k] = '\0';
}

int main(){
    char infix[20], postfix[20];
    printf("\nThis is the first print of program");

    printf("\nInput infix string: "); scanf("%s", infix);
    infix_to_postfix(infix, postfix);

    printf("\nThe postfix string is: %s", postfix);

    return 0;
}