#include<stdio.h>
#include<limits.h>

struct lnode{
    int data;
    struct lnode* next;
};

typedef struct lnode node;

struct Queue{
    node* front;
    node* rear;
};


struct Queue* createQueue(){

    struct Queue* p = (struct Queue*)malloc(sizeof(struct Queue));
    p->front = NULL;
    p->rear = NULL;

    return p; //return q pointer
};

void enqueue(struct Queue* q, int val){

    node* newNode = (node*)malloc(sizeof(node));
     if(newNode==NULL){
        printf("Out of memory");
        return;
   }

    newNode->data = val;
    newNode->next = NULL;
    if(q->rear==NULL) //adding the first element of the Q
        q->front = newNode;
    else
        q->rear->next = newNode;
    q->rear = newNode;
    printf("\nEnqueued %d",val);
}

int dequeue(struct Queue* q){
    if(q->front==NULL){
        return INT_MIN;
    }

    node* del = q->front;
    q->front = q->front->next;
    if(q->front==NULL) //when last element in the Q is delete
        q->rear = NULL;
    int temp = del->data;
    free(del);
    return temp;

}

int main(){

    struct Queue* q1 = createQueue();
    struct Queue* q2 = createQueue();
    struct Queue* q3 = createQueue();

    enqueue(q1,5);
    enqueue(q1,7);
    enqueue(q1,8);


    printf("\nDequeued %d " , dequeue(q1));
    printf("\nDequeued %d " , dequeue(q1));
    printf("\nDequeued %d " , dequeue(q1));

    enqueue(q1,5);
    enqueue(q1,7);

    printf("\nDequeued %d " , dequeue(q1));
    printf("\nDequeued %d " , dequeue(q1));



}
