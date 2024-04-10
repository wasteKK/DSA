#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#define SIZE 20

struct stack{
    int top;
    float data[SIZE];
};

typedef struct stack STACK;

void push(STACK* s, float item){
    if(s->top == SIZE-1) printf("STACK OVERFLOW\n");
    else s->data[++s->top] = item; 
}

float pop(STACK* s){
    if(s->top==-1) printf("STACK UNDERFLOW\n");
    else return s->data[s->top--];
}

float operate(float op1, char symbol, float op2){
    switch(symbol){
        case '+': return op1+op2;
        case '-': return op1-op2;
        case '*': return op1*op2;
        case '/': return op1/op2;
        case '^': return pow(op1, op2);
    }
}

float prefixEvaluate(STACK* s, char prefix[SIZE]){
    char symbol;
    float op1, op2, res;
    int i;
    for(i=strlen(prefix)-1; i>=0; i--){
        symbol = prefix[i];
        if(isdigit(symbol)) push(s, symbol-'0');
        else{
            op1 = pop(s);
            op2 = pop(s);
            res = operate(op1, symbol, op2);
            push(s, res);
        }
    }
    return pop(s);
}

int main(){
    STACK s;
    s.top=-1;
    char prefix[SIZE];
    float ans;
    printf("Read the prefix expression: \n");
    scanf("%s", prefix);
    ans = prefixEvaluate(&s, prefix);
    printf("\nThe final result after evaluating the prefix expression is: %f\n", ans);
}