#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct lnode{
    int data;
    struct lnode* next;
};

typedef struct lnode node;


void push(node **top,int val){
    node* newNode=(node*)malloc(sizeof(node));
    if(newNode==NULL){
        printf("Out of memory");
        return;
    }
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

int pop(node **top){ //O(1)
    if(*top==NULL){
        printf("stack is Empty");
        return INT_MIN;
    }
    node* del = *top;
    *top = (*top)->next;
    int temp = del->data;
    free(del);
    return temp;

}

int peek(node **top){

    if(*top==NULL){
        printf("stack is Empty");
        return INT_MIN;
    }
    return (*top)->data;
}

int main(){

    node* top = NULL;
    node* top2 = NULL;

    push(&top,3);
    push(&top,4);
    push(&top,7);
    push(&top,9);

    printf("Popped %d",pop(&top));

    return 0;
}

/*
try
insertAfter(val)
delete(val)
doubly circular linkedlist
*/
