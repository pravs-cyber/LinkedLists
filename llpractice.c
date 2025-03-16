//modify search for detecting multiple elements in a list,  fixing for loopholes and make the position +1 i think


#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node * next;
}* NODE;

NODE head=NULL;

int menu(){
    int choice;

    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Display\n");
    printf("4. Reverse\n");
    printf("5. Count Nodes\n");
    printf("6. Search an element in Nodes\n");
    printf("7. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    return choice;
}

float insertMenu(){
    float choice;

    printf("1. Insert at Beginning\n");
    printf("2. Insert at End\n");
    printf("3. Insert at a position\n");

    printf("Enter your choice: ");
    scanf("%f", &choice);

    return choice;
}

NODE createNode(){
    int value;
    NODE newNode=(NODE)malloc(sizeof(struct Node));

    printf("Enter value: ");
    scanf("%d", &value);
    
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}

void insertAtBeginning(){
    NODE temp=createNode();
    temp->next=head;
    head=temp;
}

void insertAtEnd(){
    NODE newNode=createNode();

    if(head==NULL){
        head=newNode;
        return;
    }

    NODE temp=head;

    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}

void insertAtPosition(){
    int pos=1,i;
    NODE newNode=createNode();

    printf("Enter the position where you would like to insert the node at: ");
    scanf("%d", &pos);

    if(head==NULL&&(pos!=1|| pos<=0)){
        printf("Invalid position!\n");
        free(newNode);
        return;
    }

    if(head==NULL && pos==1){
        insertAtBeginning();
        return;
    }
    NODE temp=head;
    
    for(i=1;i<pos-1 && temp!=NULL;i++){
        temp=temp->next;
    }

    if(temp==NULL){
        printf("Invalid position\n");
        free(temp);
        return;
    }

    newNode->next=temp->next;
    temp->next=newNode;
    return;
}

float deleteMenu(){
    float choice;

    printf("1. Delete at Beginning\n");
    printf("2. Delete at End\n");
    printf("3. Delete at a position\n");
    printf("4 Delete a specific element\n");

    printf("Enter your choice: ");
    scanf("%f", &choice);

    return choice;
}

void delAtBeginning(){
    if(head==NULL)
   {
        printf("No value to be deleted\n");
        return;
   }

   printf("The deleted value is: %d\n", head->data);
   NODE temp=head;
   head=head->next;

   free(temp);
   return;
}

void delAtEnd(){
    NODE temp=head, prev=NULL;

    if(head==NULL)
   {
        printf("No value to be deleted\n");
        free(temp);
        return;
   }

   if(head->next==NULL){
        delAtBeginning();
   }

   while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
   }

   printf("The deleted value is %d\n", temp->data);
   prev->next=NULL;

   free(temp);
   return;
}

void delAtPosition(){
    NODE temp=head;
    int pos=1,i;

    printf("Enter the position where you want to delete the node\n");
    scanf("%d", &pos);

    if(pos==1)
    {
        delAtBeginning();
        free(temp);
        return;
    }

    NODE prev=NULL;

    for(i=1;i<pos-1;i++){
        prev=temp;
        temp=temp->next;
    }
    
    if(temp==NULL){
        printf("Invalid position\n");
        free(prev);
        free(temp);
        return;
    }

    prev->next=temp->next;
    printf("The deleted element is: %d\n", temp->data);
    free(temp);
    return;
}

void delElement(){
    int value;
    NODE prev=NULL, temp=head;

    printf("Enter the element which you would like to delete from the list: ");
    scanf("%d", &value);

    if(head!=NULL && head->data==value){
        delAtBeginning();
        return;
    }
    while(temp!=NULL && temp->data!=value){
        prev=temp;
        temp=temp->next;
    }
    printf("The element was deleted\n");
    prev->next=temp->next;
    free(temp);
    return;

}

void display(){
    NODE temp=head;
    while(temp!=NULL){
        printf("%d -> ", temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
    return;
}

void reverse(){
    NODE prev=NULL, current=head, next=NULL;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
    return;
}

void countNodes(){
    int count=0;
    NODE temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    printf("The number of Nodes in the list are : %d\n", count);
    free(temp);
}

void searchElement(){
    int pos=1, key,found=0;
    NODE temp=head;
    printf("Enter the element you would like to search: ");
    scanf("%d", &key);
    printf("The key %d found at ", key);
    while(temp!=NULL){
        if(temp->data==key)
            {
                printf("%d position ", pos);
                found=1;
            }
            temp=temp->next;
            pos++;
    }
    if(!found)
    printf("NULL\n");
    else
    printf("\n");
}

int main()
{
    int choice,inschoice,delchoice;
    while(1){
        choice=menu();
        switch(choice){
            case 1:
            inschoice=insertMenu();
            switch(inschoice){
                case 1:
                insertAtBeginning();
                display();
                break;
                case 2:
                insertAtEnd();
                display();
                break;
                case 3:
                insertAtPosition();
                display();
                break;
                default:
                printf("Invalid choice\n");
            }
            break;
            case 2: 
            delchoice=deleteMenu();
            switch(delchoice){
                case 1:
                delAtBeginning();
                display();
                break;
                case 2:
                delAtEnd();
                display();
                break;
                case 3:
                delAtPosition();
                display();
                break;
                case 4:
                delElement();
                display();
                break;
                default:
                printf("Invalid choice\n");
            }
            break;
            case 3:
            display();
            break;
            case 4:
            reverse();
            display();
            reverse();
            break;
            case 5:
            countNodes();
            display();
            break;
            case 6:
            searchElement();
            display();
            break;
            case 7:
            exit(0);
            default:
            printf("Invalid choice!\n");
        }
    }
}