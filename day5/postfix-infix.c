#include <stdio.h>
#include <string.h>

// input: Enter the postfix string: abc*+
// output: The infix string is: (a+(b*c))

// stack functions------------------------------
char stack[20][20]; int top=-1; // a global stack 

void push(char op[20]){
   top++;
   strcpy(stack[top], op);
}


void pop(char op[20]){

   strcpy(op, stack[top]);
   top--;
}


// actual function---------------------------------
void postfix_to_infix(char post[20]){

   char op1[20]; char op2[20];
   char infixstr[20];
   char temp[2];
   char operand[2];
   operand[0] = 'a'; operand[1]  = '\0';

   printf("\nProcess in detail-----------------------------------------------");

   for(int i=0; post[i]!='\0'; i++){

       // if operator -->
       if(post[i]=='+' || post[i]=='-' || post[i]=='*' || post[i]=='/'){

           printf("\n-->Since %c is a operator, pop top 2 values.", post[i]);

           pop(op1); pop(op2); // now op1 and op2 has stack top 2 values

           printf("\nop1: %s, op2: %s.",op1, op2);

           temp[0] = post[i]; temp[1]='\0';
          
           infixstr[0] = '('; infixstr[1] = '\0';
           strcat(infixstr, op2);
           strcat(infixstr, temp);
           strcat(infixstr, op1);
           temp[0] = ')'; temp[1] = '\0';
           strcat(infixstr, temp);

           printf("\nHence the current infix string is: %s, and it is pushed in stack top", infixstr);
          
           push(infixstr);

           // printing stack:
            printf("\nCurrent the stack is as so: ");
           for(int j=top; j>=0; j--){
            printf("\n--  %s  --", stack[j]);
           }

           printf("\n-------------------");
       }
       // if operand -->
       else {

           printf("\n-->Since %c is an operand, pushed it in stack.", post[i]);
           operand[0] = post[i];
           push(operand);

            // printing stack:
            printf("\nCurrent the stack is as so: ");
           for(int j=top; j>=0; j--){
            printf("\n--  %s  --", stack[j]);
           }

           printf("\n-------------------");
       }
   }
   printf("\nAll iterations are done!");
   pop(infixstr);
   printf("\nThe final infix string is: %s\n\n", infixstr);
}


int main(){

   char postfix_input[20];

   printf("\nEnter the postfix string: "); scanf("%s", postfix_input );

   postfix_to_infix(postfix_input);

   return 0;
}

