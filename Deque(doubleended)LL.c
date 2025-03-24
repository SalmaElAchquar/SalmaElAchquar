struct node{
    int data;
    struct node *next;
}
void enqueue(intx,struct node *front){
    if(front==NULL){
        front= (stuct node *)malloc(sizeof(struct node));
        front->data=x;
        front->next=NULL;
        rear=front;
    }
    else{
        struct node *newnode;
        newnode= (stuct node *)malloc(sizeof(struct node));
        newnode->data=x;
        rear->next=newnode;
        newnode->next=NULL;
        newnode=rear;
    }
}
//insertion in the front
push(int x,struct node *front){
    if(front==NULL){
        front= (stuct node *)malloc(sizeof(struct node));
        front->data=x;
        front->next=NULL;
        rear=front;
    }
    else{
        struct node *newnode;
        newnode= (stuct node *)malloc(sizeof(struct node));
        newnode->data=x;
        newnode->next=front;
        front=newnode;
    }
}
 //deletion in front
 void dequeue(struct node *front){
    if(front== NULL)
        printf("empty");
    else{
        struct node *temp;
        temp=front;
        front=front->next;
        free(temp);
        if(front=NULL)
         rear=NULL;
    }
    
 }
 //DELETE FROM REAR END 
 pop(struct node*){
    struct node *walker;
    if(front== NULL)
        printf("empty");
    else if(front->next==NULL){
        free(front);
        front=rear=NULL;
    }
    else{
        for(walker=front;walker->next!=rear;walker=walker->next){
            free(rear);
            walker->next=NULL;
            rear=walker;
        }
    }

 }
 void display(){
    struct node *walker=front;
    if(front!=NULL){
        while(walker!=NULL){
            printf("%d",walker->data);
            printf("NULL");
            walker=walker->next;
        }
    }
    else
        printf("empty");
 }
 