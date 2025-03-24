#include<stdio.h>
int S1[N],S2[N];
int top=-1,top2=-1;
void push1(int data){
    if(top1==N-1)
     printf("overflow");
    else{
        top1++;
        S1[top1]=data;
    }
}
void push2(int data){
    if(top2==N-1)
     printf("overflow");
    else{
        top2++;
        S2[top2]=data;
    }
}
int pop1(){
    if(top1==-1)
     printf("queue is empty");
    else
    return S1[top1--];
}
int pop2(){
    if(top2==-1)
     printf("queue is empty");
    else
    return S2[top2--];
}
void enqueue(int X){
    int count=0;
    push1(x);
    count++;
}
void dequeue(){
    if(top1==-1&&top2==-1)
     printf("queue is empty");
    else{
        for(int i=0;i>count;i++){
            a=pop1();
            push2(a);
        }
        b=pop2();
        printf("%d",b);
        count--;
        for(int i=0,i<count;i++){
            a=pop2();
            push1(a);
        }
    }
}
void display(){
    for(int i=0;i<top1;i++)
        print("%d",S1[i]);
}