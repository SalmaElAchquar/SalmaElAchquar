#include<stdio.h>
struct node{
    int data;
    struct node *next;
}
struct node *front =NULL;
struct node *rear =NULL;
void enqueue(int X){
    struct node *newnode;
    newnode= (struct node*)malloc(sizeof(struct node));
    newnod->data=x;
    newnode->next=NULL;
    if(front==NULL &&rear==NULL)
        rear=front=newnode;
    else{
        rear->next=newnode;
        rear=newnode;
    }

}
void display(){
    struct node *temp;
     if(front==NULL &&rear==NULL)
        printf("empty");
     else{
        temp=front;
        while(temp!=NULL){
            printf("%d",temp->data);
            temp=temp->next
        }
     }
}
void dequeue(){
    struct node *temp;
    temp= front;
     if(front==NULL &&rear==NULL)
        printf("empty");
     else{
        front=fron->next;
        free(temp);
     }
}void peek(){
     if(front==NULL &&rear==NULL)
        printf("empty");
     else
        printf("%d",front->data);
}