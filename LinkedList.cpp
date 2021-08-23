#include<stdio.h>
#include<stdlib.h>


struct lnode{//define node
    int data;
    lnode* next; //self referential str
};


typedef struct lnode node;


class LinkedList{

    node* head = NULL;
public:
    void insertAtBeginning(int val){
    node* newNode=(node*)malloc(sizeof(node)); //allocate
    if(newNode==NULL){
        printf("Out of memory");
        return;
   }

   newNode -> data = val;
   if(head == NULL){ //when list is empty
        newNode -> next = NULL;
        head = newNode;
   }
   else{ //when there is atleast one node
        newNode -> next = head;
        head = newNode;
   }

   printf("Inserted %d at the beginning",val);
}

void display(){
    if(head==NULL){
        printf("List is empty");
        return;
    }
    node* temp = head;

    printf("Elements in the list are: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }


}

void insertAtPos(int pos,int val){
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
   temp -> next = newNode;

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
    printf("Deleted %d",temp -> data);
    free(temp);

}

};


int main(){
    int choice,val,pos;
    LinkedList list1;
    LinkedList list2;
    while(1){
        printf("\n -------- Linked List Menu -----------\n");
        printf("1.Insert at Beginning\n");
        printf("2.Display the list\n");
        printf("3.Insert at specified position \n");
        printf("4.Delete from specified position\n");
        printf("5.Exit\n");
        printf("\n--------------------------------------\n");
        printf("Enter your choice:\t");
        scanf("%d",&choice);
        switch(choice){
        case 1: printf("Enter the data: ");
                scanf("%d",&val);
                list1.insertAtBeginning(val);
                break;
        case 2: list1.display();
                break;
        case 3: printf("Enter the pos\(starts at 0\): ");
                scanf("%d",&pos);
                if(pos<0){
                    printf("Invalid position");
                    break;
                }
                printf("Enter the data: ");
                scanf("%d",&val);
                if(pos==0)
                    list1.insertAtBeginning(val);
                else
                    list1.insertAtPos(pos,val);
                break;
        case 4: printf("Enter the pos: ");
                scanf("%d",&pos);
                if(pos<0){
                    printf("Invalid position");
                    break;
                }
                list1.deleteAtPos(pos);
                break;
        case 5: exit(0);

        default: printf("Wrong choice");


        }
    }
    return 0;
}
