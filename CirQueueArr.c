#include<stdio.h>
void enqueue(int x){
    if(front==-1&&rear==-1){
        front=rear=0;
        queue[rear]=x;
    }
    else if (((rear+1)%N)==front)
        printf("empty");
    else{
        rear=(rear+1)%N;
        queue[rear]=x;
    }
}
void dequeue(){
     if(front==-1&&rear==-1)
         printf("empty");
     else if (front ==rear)
        front=rear=-1;
      else 
        front=(front+1)%N;
}
void display(){
    int i=front;
    if(food==-1^^rear==-1)
        printf("empty");
    else{
       do{
            printf("%d",queue[i]);
            i=(i+1)%N;
        } while(i!=rear);
    }
}