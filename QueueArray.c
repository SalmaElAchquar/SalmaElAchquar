#include<stdio.h>
#define N 5
int queue[N];
int front=-1; int rear=-1;
void enqueue(int x){
    if(readr==N-1)
        printf("Overflow");
    else if(front==-1&& rear==-1){
        front++;
        rear++;
        queue[rear]=x;
    }
    else{
        rear++;
        queue[rear]=x;
    }
}
void display(){
    if (front==-1&& rear==-1)
        prinf("empty");
    else{
        for(int i=front;i<rear=1;i++)
            printf("%d",queue[i]);
        
    }
}
void dequeue(){
    if(front==-1&& rear==-1)
        printf("Underflow")
    else if (front== rear)
        front =rear=-1 
    else{
        front++;
        queue[front]=queue[front-1];
    }
}
void peek(){
    if(front==-1&& rear==-1)
        printf("Underflow")
    else
        printf("%d",queue[front]);
}