#include<stdio.h>
#include<stdlib.h>

/* Doubly Linked List - c/cpp */
struct lnode{//define node
    int data;
    struct lnode* prev;
    struct lnode* next; //self referential str
};


typedef struct lnode node;

node* head = NULL;
node* tail = NULL;

node* head2 = NULL;
node* tail2 = NULL;

void insertAtBeginning(int val){
    node* newNode=(node*)malloc(sizeof(node)); //allocate
    if(newNode==NULL){
        printf("Out of memory");
        return;
   }
   newNode -> data = val;
   newNode -> next = head;
   if(head == NULL){ //when list is empty
        tail = newNode;
   }
   else{ //when there is atleast one node
        head->prev = newNode;
   }
   head = newNode;
   newNode->prev = NULL;

   printf("\nInserted %d at the beginning",val);
}

void display(){
    if(head==NULL){
        printf("List is empty");
        return;
    }
    node* temp = head;

    printf("\nElements in the list are: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next; //jump
    }
}

void displayRev(){
    if(tail==NULL){
        printf("List is empty");
        return;
    }
    node* temp = tail;

    printf("\nElements in rev: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->prev; //jump
    }
}


void insertAtPos(int pos,int val){
    if(pos==0){
        insertAtBeginning(val);
        return;
    }

    int i;
    node* newNode=(node*)malloc(sizeof(node)); //allocate
    if(newNode==NULL){
        printf("Out of memory");
        return;
   }

   newNode->data = val;

   node* temp = head;

   for(i=1;i<=pos-1;i++){ //jump to prev node
        temp = temp -> next;
        if(temp==NULL){
           printf("Invalid position\n");
           return;
        }
   }

   newNode -> next = temp -> next;
   if(temp->next==NULL)
      tail = newNode;
   else
    temp->next->prev = newNode;

   temp -> next = newNode;
   newNode -> prev = temp;

   printf("Inserted %d at pos %d",val,pos);
}

void deleteAtPos(int pos){
    int i;
    node* temp = head;
    node* prev;
    if(head==NULL){
        printf("List is empty ");
        return;
    }

    if(pos==0){
        head = head -> next;
        if(head==NULL)
            tail = NULL;
        else
             head->prev = NULL;
        printf("Deleted %d",temp -> data);
        free(temp);
        return;
    }

    for(i=1;i<=pos;i++){
        prev = temp;
        temp = temp -> next;
        if(temp==NULL){
               printf("Invalid position\n");
               return;
        }
    }

    prev -> next = temp -> next;

    if(temp->next==NULL)
        tail = prev;
    else
        temp->next->prev = prev;
    printf("Deleted %d",temp -> data);
    free(temp);

}


int main(){
   // insertAtBeginning(&head,&tail,3);
   // insertAtBeginning(&head2,&tail2,7);
    insertAtBeginning(4);
   /* insertAtBeginning(7);
    insertAtBeginning(9);*/
    display();
    deleteAtPos(0);
    display();
    displayRev();
    return 0;
}


/*
loop- O(n)
O(1)

insertAtEnd
deleteAtEnd
deleteAtBeginning
search
contains
length

*/
