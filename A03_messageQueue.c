#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 5

struct queue{
    int front , rear;
    char data[SIZE][20];
};

typedef struct queue QUEUE;

void sender(QUEUE* q, char item [20]){
    if(q->front == (q->rear+1)%SIZE) printf("QUEUE IS FULL\n");
    else{
        q->rear = (q->rear+1)%SIZE ;
        strcpy(q->data[q->rear] , item); //
        if(q->front == -1) q->front = 0; //
    }
}

char* receiver(QUEUE* q){
    char* del;
    if(q->front == -1){
        printf("QUEUE IS EMPTY\n");
        return NULL;
    }
    del = q->data[q->front];
    if(q->front == q->rear){
        q->front = -1;
        q->rear = -1;
        return del;
    }
    else{
        q->front = (q->front+1)%SIZE;
        return del;
    }
}

void display(QUEUE q){
    int i;
    if(q.front == -1) printf("QUEUE IS EMPTY\n");
    else{
        printf("\nThe content of the queue are:\n");
        for(i=q.front; i!=q.rear; i=(i+1)%SIZE){
            printf("%s\n", q.data[i]);
        }
        printf("%s\n", q.data[i]);
    }
}


int main(){
    QUEUE q;
    q.front = q.rear = -1;
    int ch;
    char item[20];
    char* del;
    while(1){
        printf("\nOPERATIONS:\n----------\n1. ENQUEUE\n2. DEQUeue\n3. DISPLAY\n4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        getchar();
        switch(ch){
            case 1: printf("Enter the item to be inserted: ");
            gets(item);
            sender(&q, item);
            break;

            case 2: del = receiver(&q);
            if(del!=NULL) printf("The element deleted is: %s\n", del);
            break;

            case 3: display(q);
            break;

            default: exit(0);
        }
    }
}

