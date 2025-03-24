//Write a function to reverse the elements of a queue using recursion or a stack.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct nd {
    int num;
    struct nd* next;
} node;
void reverse_recur(node**front,node**rear);
void enqueue(node**front,node**rear,node*ToEnqueue){
    if(*front==NULL){
        *front=ToEnqueue;
        *rear=ToEnqueue;
    }
    else{
        (*rear)->next=ToEnqueue;
        *rear=(*rear)->next;
    }
}

int dequeue(node**front){                              
    int x;
    if(*front==NULL)
        return -1;
    else{
        node*temp=*front;
        *front=(*front)->next;
        x= temp->num;
        free(temp);
        return x;
    }
}
int main(){
    int N;
    char choice[4];
    node* front=NULL,*rear=NULL;
    printf("Please enter YES/NO if you want to try : \n");
    scanf("%3s",choice);
    if(strcmp(choice, "YES") == 0){
        printf("Please enter the number of elements you want to test: \n");
        scanf("%d", &N);
        printf("Enter the elements:\n");
        for (int i = 0; i < N; i++) {
            int value;
            scanf("%d", &value);
             
            node* newNode = (node*)malloc(sizeof(node));
            newNode->num = value;
            newNode->next = NULL;
            enqueue(&front, &rear,newNode);
        }
   
    printf("The reveres queue is : \n");
    reverse_recur(&front, &rear);
    while (front != NULL) {
            printf("%d ", dequeue(&front));
        }
    }
    else
        printf("THANK YOU!!\n");
return 0;
}
void reverse_recur(node**front,node**rear){
    if((*front)==NULL)
        return;
     int dequeued=dequeue(front);
    reverse_recur(front,rear);
    node* newNode = (node*)malloc(sizeof(node));
    newNode->num = dequeued;
    newNode->next = NULL;
    enqueue(front,rear,newNode);
}





