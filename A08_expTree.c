#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define SIZE 10

struct node{
    char data;
    struct node *left, *right;
};
typedef struct node* NODE;

struct stack{
    int top;
    NODE data[SIZE];
};
typedef struct stack STACK;

void preorder(NODE root){
    if(root!=NULL){
        printf("%c\t", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(NODE root){
    if(root!=NULL){
        inorder(root->left);
        printf("%c\t", root->data);
        inorder(root->right);
    }
}

void postorder(NODE root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%c\t", root->data);
    }
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

NODE create_node(char item){
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void push(STACK* s, NODE item){
    s->data[++s->top] = item;
}

NODE pop(STACK* s){
    return s->data[s->top--];
}

NODE createExpTree(NODE root, char infix[SIZE]){
    
    STACK ts, os;
    ts.top = -1;
    os.top = -1;
    int i;
    char symbol;
    NODE temp, t;

    for(i = 0; infix[i]!='\0'; i++){
        symbol = infix[i];
        temp = create_node(symbol);
        if(isalnum(symbol)) push(&ts, temp);
        else{
            if(os.top==-1) push(&os, temp);
            else{
                while( os.top!=-1 && preced(os.data[os.top]->data) >= preced(symbol)){
                    t = pop(&os);
                    t->right = pop(&ts);
                    t->left = pop(&ts);
                    push(&ts, t);
                }
                push(&os, temp);
            }
        }
    } 

    while(os.top!=-1){
        t = pop(&os);
        t->right = pop(&ts);
        t->left = pop(&ts);
        push(&ts, t);
    }

    return pop(&ts);
}

int main(){
    NODE root = NULL;
    char infix[SIZE];
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    root = createExpTree(root, infix);
    printf("\nPreorder:\n");
    preorder(root);
    printf("\nInorder:\n");
    inorder(root);
    printf("\nPostorder:\n");
    postorder(root);
}

