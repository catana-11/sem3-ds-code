#include <stdio.h>
#include <string.h>

// input: abc*+ -> postfix
// output: +a*bc -> prefix


// stack functions------------------------------
char stack[20][20]; int top=-1;

void push(char op[20]){
   top++;
   strcpy(stack[top], op);
}


void pop(char op[20]){
   strcpy(op, stack[top]);
   top--;
}

// actual function---------------------------------
void post_to_pre(char post[20]){

   char op1[20]; char op2[20];
   char prefixstr[20] = "";
   char temp[2];
  
   char operand[2];
   operand[0] = 'a'; operand[1]  = '\0'; // alloting random value

   printf("\nProcess in detail-----------------------------------------------");
   for(int i=0; post[i]!='\0'; i++){


       // if operator -->
       if(post[i]=='+' || post[i]=='-' || post[i]=='*' || post[i]=='/'){

            printf("\n-->Since %c is a operator, pop top 2 values.", post[i]);

           char tempprefixed[20] = "";     // declaring blank string to edit and enter in stack everytime


           pop(op1); pop(op2); // now op1 and op2 has stack top 2 values
           printf("\nop1: %s, op2: %s\n", op1, op2);


           temp[0] = post[i];  temp[1]='\0';
      
           strcat(tempprefixed, temp);
           strcat(tempprefixed, op2);
           strcat(tempprefixed, op1);
        
           push(tempprefixed);
           printf("\nThe prefix pushed now: %s\n", tempprefixed);

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


   pop(prefixstr);
   printf("\nAnswer: The prefix string is: %s\n\n", prefixstr);


}


int main(){

   char postfix_input[20];
   printf("\nEnter the postfix string: "); scanf("%s", postfix_input );

   post_to_pre(postfix_input);

   return 0;

}

