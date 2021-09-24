#include<stdio.h>
#define MAX_SIZE 50
int arr[MAX_SIZE];
int size = 0;


void display(){
    int i;
    for(i=0;i<size;i++)
        printf("%d\t",arr[i]);

}

void insertAtPos(int pos,int val){
    int i;

    for(i=size-1;i>=pos;i--){
        arr[i+1]=arr[i];
    }

    arr[pos]= val;
    size++;
    printf("Inserted %d at pos %d",val,pos);
}

void deleteFromPos(int pos){
    int i;
    int del = arr[pos];
    for(i=pos;i<size;i++){
        arr[i] = arr[i+1];
    }
    size--;
    printf("Deleted %d at pos %d",del,pos);
}
int main(){
    int choice,val,pos;
    while(1){
        printf("\n -------- List Menu -----------\n");
        printf("1.Insert at end \n");
        printf("2.Insert at specified pos \n");
        printf("3.Delete at specified pos \n");
        printf("4.Display\n");
        printf("5.Exit\n");
        printf("\n--------------------------------------\n");
        printf("Enter your choice:\t");
        scanf("%d",&choice);
        switch(choice){
        case 1: printf("Enter the data: ");
                scanf("%d",&val);
                arr[size++] = val;
                break;
        case 2: if(size == MAX_SIZE){
                    printf("Array is full");
                    break;
                }
                printf("Enter the pos\(pos starts at 0\):  ");
                scanf("%d",&pos);
                if(pos<0 || pos>=size)
                {
                    printf("Invalid position");
                    break;
                }
                printf("Enter the data: ");
                scanf("%d",&val);
                insertAtPos(pos,val);
                break;
        case 3: if(size==0){
                    printf("Array is empty");
                    break;
                }
                printf("Enter the pos: ");
                scanf("%d",&pos);
                if(pos<0 || pos>=size)
                    printf("Invalid position");
                else
                    deleteFromPos(pos);
                break;

        case 4: display();
                break;
        case 5: exit(0);

        default: printf("Wrong choice");
                 break;
        //read,update,search,length,deleteAtEnd,deleteFromBeginning,insertAtBeginning

        }
    }
    return 0;
}
