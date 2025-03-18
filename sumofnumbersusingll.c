#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int data;
    struct Node * next;
}* NODE;

NODE createNode(long int value){
    NODE newNode=(NODE)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}

NODE insertNode(NODE head, long int value){
    NODE newNode=createNode(value);
    newNode->next=head;
    return newNode;
}

void display(NODE head){
    NODE prev=NULL, current=head, next=NULL;

    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
    printf("Sum of the number is: ");
    while(head!=NULL){
        printf("%d", head->data);
        head=head->next;
    }
    printf("\n");
}

NODE addtwoNumbers(NODE l1, NODE l2){
    NODE head=NULL, tail=NULL;
    int carryOver=0;

    while(l1!=NULL || l2!=NULL || carryOver>0){
        int sum=carryOver;
        
        if(l1!=NULL){
            sum+=l1->data;
            l1=l1->next;
        }
        
        if(l2!=NULL){
            sum+=l2->data;
            l2=l2->next;
        }

        if(sum>=10)
        carryOver=sum/10;
        else   
        carryOver=0;
        
        NODE newNode=createNode(sum%10);

        if(head==NULL){
            head=newNode;
            tail=newNode;
        }

        else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    return head;
}

NODE numberConvert(char * num){
    NODE head=NULL;
    long int len=strlen(num);
    for(int i=0;i<len;i++){
        head=insertNode(head, num[i]-'0');
    }
    return head;
}

int main(){
    char num1[200], num2[200];
    NODE l1, l2,result;

    printf("Enter the first number you would like to add: ");
    scanf("%s", num1);

    printf("Enter the second number you would like to add: ");
    scanf("%s", num2);
    
    l1=numberConvert(num1);
    l2=numberConvert(num2);

    result=addtwoNumbers(l1, l2);

    display(result);
    return 0;
}
