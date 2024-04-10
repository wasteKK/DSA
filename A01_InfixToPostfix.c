#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define SIZE 20

struct stack{
    int top;
    char data[SIZE];
};

typedef struct stack* STACK;

void push(STACK s, char item){
    if(s->top == SIZE-1) printf("STACK OVERFLOW\n");
    else s->data[++s->top] = item; 
}

char pop(STACK s){
    if(s->top==-1) printf("STACK UNDERFLOW\n");
    else return s->data[s->top--];
}

int preced(char symbol){
    switch(symbol){
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
    }
}

void infixToPostfix(STACK s, char infix[SIZE]){
    char postfix[SIZE], symbol,temp;
    int i=0,j=0;
    for(i=0; infix[i]!='\0'; i++){
        symbol = infix[i];
        if(isalnum(symbol)) postfix[j++] = symbol;
        else{
            switch(symbol){
                case '(': push(s,symbol);
                    break;

                case ')': 
                    temp = pop(s);
                    while(temp!='('){
                        postfix[j++] = temp;
                        temp = pop(s);
                    }
                    break;
                
                case '^': 
                case '*':
                case '/':
                case '+':
                case '-':
                if(s->top==-1 || s->data[s->top]=='(') push(s,symbol);
                else{
                    while(preced(s->data[s->top]) >= preced(symbol) && s->top!=-1 && s->data[s->top]!='('){
                        postfix[j++] = pop(s);
                        // printf("%d\n",s->top);
                    }
                    push(s,symbol);
                }
            }
        }
    }
    while(s->top!=-1) postfix[j++] = pop(s);
    postfix[j]='\0';

    printf("\nThe equivalent postfix expression is:  %s\n", postfix);
}

int main(){
    STACK s;
    s->top=-1;
    char infix[SIZE];
    printf("Read the infix expression: \n");
    scanf("%s", infix);
    infixToPostfix(s, infix);
}