#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

int count;

struct node{
    int data;
    struct node* addr;
};
typedef struct node* NODE;

NODE enqueue(NODE last, int item){
    // if(count>=SIZE){
    //     printf("QUEUE IS FULL\n");
    //     return last;
    // }
    
    NODE temp = (NODE)malloc(sizeof(struct node));
    count++;
    temp->data = item;
    if(last == NULL){
        temp->addr = temp;
        return temp;
    }
    temp->addr = last->addr;
    last->addr = temp;
    return temp;
}

NODE dequeue(NODE last){
    NODE temp;
    if(last == NULL){
        printf("QUEUE IS EMPTY\n");
        return last;
    }
    count--;
    if(last->addr == last){
        printf("The node deleted is %d\n", last->data);
        free(last);
        return NULL;
    }
    temp=last->addr;
    last->addr = temp->addr;
    printf("The node deleted is %d\n", temp->data);
    free(temp);
    return last;
}

void display(NODE last){
    NODE temp;
    if(last == NULL){
        printf("QUEUE IS EMPTY\n");
        return;
    }
    printf("The content of queue is:\n");
    temp = last->addr;
    while(temp!=last){
        printf("%d\t", temp->data);
        temp = temp->addr;
    }
    printf("%d\t", last->data);

}

int main(){
    NODE last = NULL;
    int choice,item;
    while(1){
        printf("\nOPERATIONS\n----------\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
    
        switch(choice){
            case 1: 
                if(count>=SIZE){
                    printf("QUEUE IS FULL\n");
                    break;
                }
                printf("Enter the item to be inserted: ");
                scanf("%d",&item);
                last = enqueue(last, item);
                break;

            case 2:
                last = dequeue(last);
                break;

            case 3:
                display(last);
                break;

            default: exit(0);
        }
    }
}