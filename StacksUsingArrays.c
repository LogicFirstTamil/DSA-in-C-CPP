#include<stdio.h>
#include<limits.h>
#define MAX_SIZE 20

struct Stack{
    int arr[MAX_SIZE];
    int top ;
};

struct Stack* createStack(){
    struct Stack* p = (struct Stack*)malloc(sizeof(struct Stack));
    p->top = -1;
    return p;
}

void push(struct Stack *stack,int val){ //O(1)
    if(stack->top==MAX_SIZE-1){
        printf("Stack is Full");
        return;
    }
    stack->arr[++stack->top] = val;

}

int pop(struct Stack *stack){
    if(stack->top==-1){
        printf("stack is Empty");
        return INT_MIN;
    }
    return stack->arr[stack->top--];
}

int peek(struct Stack *stack){

    if(stack->top==-1){
        printf("stack is Empty");
        return INT_MIN;
    }
    return stack->arr[stack->top];
}


int main(){
    struct Stack *S = createStack();
    struct Stack *S2 = createStack();


    push(S,5);
    push(S,7);
    push(S2,3);

    printf("\nPopped %d " , pop(S));


}
