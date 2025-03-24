
#include<stdio.h>
#include<string.h>
int t_number=1;
void menu();
typedef struct{
    char name[50];
    int t_num;
}c_info;
void menu();
int enqueue(c_info *queue, int *rear, int size, c_info toEnqueue, int *front);
void dequeue(c_info *queue, int *rear, int *front, int size);
void display_content_queue(c_info *queue, int front, int rear, int size);
void quit_queue(c_info *queue,int* front,int* rear,int size,char *client_name);
int main(){
int front=-1,rear=-1,choice,size=5,x;
c_info queue[size];
c_info toEnqueue;
    do{
        menu();
        scanf("%d",&choice);
        switch(choice){
            case 1:
            if((rear + 1) % size != front){
            printf(" please enter the name of the client: \n");
            scanf("%s",toEnqueue.name);
            toEnqueue.t_num=t_number++;
            x=enqueue(queue,&rear,size,toEnqueue,&front);
                if(x==1)
                    printf("Successsfully added to the queue.\n");
                else
                    printf("SORRY! You were not added to the queue.\n");
            }
            else
            printf("the queue is full.\n");    
            break;
            case 2:
            if (front != -1) {
                dequeue(queue, &rear, &front, size);
                printf("The client was served successfully.\n");
            } 
            else 
                printf("The queue is empty.\n");
            break;
            case 3:
            display_content_queue(queue,front,rear,size);
            break;
            case 4:
            char client_name[50];
            printf("Enter the name of the client who wants to quit the queue: ");
            scanf("%s", client_name);
            quit_queue(queue, &front, &rear, size, client_name);
            break;
            case 5:
            printf("THANK YOU! BYE!");
            break;
            default:
            printf("ERROR: Invalid choice\n");
        }

    } while(choice!=5);
return 0;
}
void menu(){
    printf("\n1. Add a New Client\n"
            "2. Serve a Client\n"
            "3. Print List of Clients in the Queue\n"
            "4. Quit the Queue\n"
            "5. End the Program\n");
}
int enqueue(c_info *queue,int*rear,int size,c_info toEnqueue,int* front){
    if((*front==-1)&&(*rear==-1)){
        *front=*rear=0;
        queue[*rear]=toEnqueue;
        return 1;
    }
    else if ((((*rear)+1)%size)==*front)
            return 0;
    else{
        *rear=((*rear)+1)%size;
        queue[*rear]=toEnqueue;
        return 1;
    }
}
void dequeue(c_info *queue,int*rear,int*front,int size){
    if((*front==-1)&&(*rear==-1))
        printf("The queue is empty\n");
    else if (*front==*rear)
        (*front)=(*rear)=-1;
    else 
        *front=((*front)+1)%size;
}
void display_content_queue(c_info *queue,int front,int rear,int size){
    if(front==-1&&rear==-1)
        printf("the queue is empty");
        else{
         int i=front;
            printf("The List of the clients : \n");
        do{
            printf(" The name of the client %s, The number of the client's ticket %d\n",queue[i].name,queue[i].t_num);
            i=(i+1)%size;
        }while(i!=(rear+1)%size);
}
}

void quit_queue(c_info *queue,int* front,int* rear,int size,char *client_name){
        if (*front == -1 && *rear == -1) {
        printf("The queue is empty.\n");
        return;
        }
        int i=*front;
        int found=0;
        do{
            if(strcmp(queue[i].name,client_name)==0){
                found=1;
                break;
            }
            i=(i+1)%size;
        }while (i != (*rear + 1) % size);
        if(found==1){
             while (i != *rear) {
            queue[i] = queue[(i + 1) % size];
            i = (i + 1) % size;
        }
        *rear = (*rear - 1 + size) % size;
        if (*rear == -1) {
            *front = -1;
        }
        printf("The client %s quit the queue \n",client_name);
    } 
    else 
        printf("Client %s not found in the queue.\n", client_name);
}

 

