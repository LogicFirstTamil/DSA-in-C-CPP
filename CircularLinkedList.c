#include<stdio.h>
#include<stdlib.h>


struct lnode{//define node
    int data;
    struct lnode* next; //self referential str
};


typedef struct lnode node;

node* last = NULL;

void insertAtBeginning(int val){
    node* newNode =(node*)malloc(sizeof(node));
    if(newNode==NULL){
        printf("Out of Memory");
        return;
    }

    newNode->data = val;
    if(last==NULL){ //list is empty
        newNode->next = newNode;
        last = newNode;
    }
    else{
        newNode->next = last->next;
        last->next = newNode;
    }
    printf("\nInserted %d at the beginning",val);
}

void display(){
    if(last==NULL){
        printf("List is empty");
        return;
    }
    printf("\nElements in the list are: ");
    node* temp = last->next;
    do{
        printf("%d ",temp->data);
        temp = temp->next;
    }while(temp!=last->next);

}

void insertAtEnd(int val){
    node* newNode =(node*)malloc(sizeof(node));
    if(newNode==NULL){
        printf("Out of Memory");
        return;
    }

    newNode->data = val;
    if(last==NULL){ //list is empty
        newNode->next = newNode;
        last = newNode;
    }
    else{
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
    printf("\nInserted %d at the beginning",val);
}

void deleteAtBeginning(){
    if(last==NULL){
        printf("List is empty");
        return;
    }

    node* del;

    if(last->next == last){ //only one element in list
        del = last;
        last = NULL;
    }
    else{
        del= last->next;
        last->next = last->next->next;
    }
    printf("\ndeleted %d",del->data);
    free(del);

}

void deleteAtEnd(){
    if(last==NULL){
        printf("List is empty");
        return;
    }

    node *del,*temp;


    if(last->next == last){ //only one element in list
        del = last;
        last = NULL;
    }
    else{
        temp = last->next;
        while(temp->next!=last){
            temp = temp->next;
        }
        del = last;
        temp->next = last->next;
        last = temp;

    }
    printf("\ndeleted %d",del->data);
    free(del);
}
int main(){
    insertAtEnd(3);
    //insertAtEnd(4);
    //insertAtEnd(5);
    display();

    deleteAtEnd();
    display();

    return 0;
}

/*
try
insertAfter(val)
insertBefore(val)
delete(val)
doubly circular linkedlist
*/
