#include<stdio.h>
struct node {
    int data 
     struct node *front=NULL;
     struct node *rear=NULL;
}
void enqueue(int x){
    struct node * newnode;
    newnode= (struct node *) malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    if(rear==NULL){
        front=rear=newnode;
        rear->next=front;
    }
    else{
        rear->next=newnode;
        rear=newnode;
        rear->next=front;
    }
}
void dequeue(){
    struct node *temp=front;
    if(front==NULL && rear==rear)
        printf("empty")
    else if(front==rear){
        front=rear=NULL;
        free(temp);
    }
    else{
        front=front->next;
        rear->next=front;
        free(temp);
    }
}
void peek(){
    if(front==NULL && rear==rear)
        printf("empty")
    else
         printf("%d",front->data);
}
void display(){
    if(front==NULL && rear==rear)
        printf("empty")
    else{
        struct node *walker=front;
        do{
            printf("%d",walker->data);
            walker=walker->next;
            }while((walker->next)!=front);
        }
    }
