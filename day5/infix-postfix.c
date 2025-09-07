#include <stdio.h>
#include <string.h>

// input = (a+b)/c
// output = ab+c/

int isp(char ch) {
    if (ch == '+' || ch == '-') return 1;
    else if (ch == '*' || ch == '/') return 2;
    else if (ch == '^') return 3;
    else if (ch == '(') return 0;
    else return -1;
}

int icp(char ch) {
    if (ch == '+' || ch == '-') return 1;
    else if (ch == '*' || ch == '/') return 2;
    else if (ch == '^') return 4;
    else if (ch == '(') return 5;
    else return -1;
}

// stack functions------------------------------
char stack[20]; int top=-1;

void push(char op){
   top++;
   stack[top]= op;
}

void pop(char* op){
   *op = stack[top];
   top--;
}


// Actual functions----------------------------
void infix_to_postfix(char infix[20]){

char poststr[20] = "";
char operand;
int k = 0;

for(int i=0; infix[i]!='\0'; i++){

        if(infix[i]=='('){

            printf("\nCurrent operator is: %c", infix[i]);
            
            push('(');      // opening bracket has the least value so just push it in stack

            // printing stack:
            printf("\nCurrent the stack is as so: ");
            for(int j=top; j>=0; j--){
                printf("\n--  %c  --", stack[j]);
            }
           printf("\n-------------------");

        }


        else if(infix[i]==')'){

            printf("\nCurrent operator is: %c", infix[i]);

            // pop into answer string until we find opening bracket:
            while(stack[top]!='('){
                pop(&operand);
                poststr[k++]= operand;
            }

            pop(&operand); // pop the closing bracket but dont add it in string

            // printing stack:
            printf("\nCurrent the stack is as so: ");
            for(int j=top; j>=0; j--){
                printf("\n--  %c  --", stack[j]);
            }
            printf("\n-------------------");

        }


        else if (infix[i]=='+' || infix[i]=='-' || infix[i]=='*' || infix[i]=='/' ){

            printf("\nCurrent operator is: %c", infix[i]);

            while(top >= 0 && isp(stack[top]) >= icp(infix[i]))
                {
                    pop(&operand);
                    poststr[k++] = operand;
                }

            push(infix[i]);

            // printing stack:
            printf("\nCurrent the stack is as so: ");
            for(int j=top; j>=0; j--){
                printf("\n--  %c  --", stack[j]);
            }
            printf("\nThe current postfix string is: %s", poststr);
            printf("\n-------------------");

        }
    
       

        else {
            printf("\n-->Since %c is a operand, push in final string.", infix[i]);
            poststr[k++] = infix[i];

            printf("\nThe current postfix string is: %s", poststr);
            printf("\n-------------------");

        }
   }

   while(top>=0){
       pop(&operand);
       poststr[k++] = operand;
   }

   poststr[k] = '\0';

   printf("\nThe final postfix string is: %s", poststr);
}


int main(){
   char infix_input[20];

   printf("\nEnter the infix string: "); scanf("%s", infix_input);
   infix_to_postfix(infix_input);

   return 0;
}