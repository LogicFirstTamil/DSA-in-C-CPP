#include<stdio.h>
#include<limits.h>

#define MAX_SIZE 30

struct Queue{
    int arr[MAX_SIZE];
    int rear;
};

struct Queue* createQueue(){
    struct Queue* p = (struct Queue*)malloc(sizeof(struct Queue));
    p->rear = -1;
    return p;
}

void enqueue(struct Queue* Q,int val){
    if(Q->rear==MAX_SIZE-1){
        printf("Queue is full");
        return;
    }

    Q->arr[++(Q->rear)] = val;

}

int dequeue(struct Queue* Q){

    if(Q->rear==-1){
        printf("Queue is Empty");
        return INT_MIN;
    }
    int temp = Q->arr[0];
    int i;


    for(i=1;i<=Q->rear;i++)
        Q->arr[i-1] = Q->arr[i];

    Q->rear--;
    return temp;

}

int elementAtFront(struct Queue* Q){
    if(Q->rear==-1){
        printf("Queue is Empty");
        return INT_MIN;
    }
    return Q->arr[0];
}

int isEmpty(struct Queue* Q){
    if(Q->rear==-1){
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

    printf("\nDequeued %d",dequeue(q));
    printf("\nDequeued %d",dequeue(q));
    printf("\nDequeued %d",dequeue(q));
    printf("\nDequeued %d",dequeue(q));

    enqueue(q,5);
    printf("\nDequeued %d",dequeue(q));

}
