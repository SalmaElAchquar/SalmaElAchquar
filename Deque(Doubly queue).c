#include<stdio.h>
#define N 5
int deque[N];
int front=-1,rear=-1;
void enqueueFront(int x){
    if(front==0 && rear==N-1)
        printf("queue is full");
    else if(front==-1&&rear==-1){
        front=rear=0;
        deque[front]=x;
    }
    else if(front==0){
         front=N-1;
         deque[front]=x;
    }
    else{
        front--;
        deque[front]=x;
    }
}
void enqueuerear(int x){
    if(front==0&&rear==N-1)
        printf("queue is full");
    else if(front==-1&&rear==-1){
         front=rear=0;
        deque[rear]=x;
    }
    else if(rear=N-1){
        rear=0;
        deque[rear]=x;
    }
    else{
        rear++;
        deque[rear]=x;
    }
}
void display(){
    int i=front;
    do{
        printf("%d",deque[i]);
        i=(i+1)%N;
    } while(i!=rear);
}
void getfront(){//same for getrear
    if(front==-1&&rear==-1)
        printf("queue is empty");
    else
        printf("%d",deque[front];)
}
void dequefront(){
    if(front==-1&&rear==-1)
        printf("queue is empty");
    else if(front==rear)
        front=rear=-1;
    else if(front==N-1)
        front=0;
    else
        frot++;
    
}
void dequeueRear(){
    if(front==-1&&rear==-1)
        printf("queue is empty");
    else if(front==rear)
        front=rear=-1;
    else if(rear==0)
        rear=N-1;
    else
        rear--;
}