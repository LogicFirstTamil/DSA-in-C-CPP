#include<stdio.h>
#include<limits.h>

#define MAX_SIZE 30

struct Queue{
    int arr[MAX_SIZE];
    int front,rear;
};

struct Queue* createQueue(){
    struct Queue* p = (struct Queue*)malloc(sizeof(struct Queue));
    p->front = -1;
    p->rear = -1;
    return p;
}

void enqueue(struct Queue* Q,int val){
    if(Q->rear==MAX_SIZE-1){
        printf("Queue is full");
        return;
    }
    if(Q->front==-1) //when adding first element of Q
        Q->front++;

    Q->arr[++(Q->rear)] = val;

}

int dequeue(struct Queue* Q){
    if(Q->front==-1 || Q->front>Q->rear){//no elements added or all elements added have been dequeued
        printf("\nQueue is empty");
        return INT_MIN;
    }

    return Q->arr[Q->front++];
}

int elementAtFront(struct Queue* Q){
    if(Q->front==-1 || Q->front>Q->rear){
        printf("\nQueue is empty");
        return INT_MIN;
    }

    return Q->arr[Q->front];
}

int isEmpty(struct Queue* Q){
    if(Q->front==-1 || Q->front>Q->rear){
        return 1;
    }

    return 0;
}

int main(){

    struct Queue *q = createQueue();
    struct Queue *q2 = createQueue();
    struct Queue *q3 = createQueue();

    enqueue(q,5);
    enqueue(q,7);
    enqueue(q,4);
    enqueue(q2,1);

    printf("Dequeued %d",dequeue(q));

}
