#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct {
  int id; 
  char s_name[100]; 
  char a_name[100];
  char s_major[100];
  double cgpa;  
}data;
typedef struct st{
    data d;
    struct st *next;
}node;

void menu(void); 
void traverse_LL(node*);
void add_node(node**phead,node*ToAdd);
node* create_LL(FILE*);
node* create_fill_node(void);
int delete_student(node**,int);
int count_students(node*head);
void sort_students(node**phead);
/*         Main Function        */
int main(void){
  int choice,status=0, n_students; 
  node*head=NULL,*tail=NULL,*ToAdd;
  FILE*infp;
  int id_tosearch;
  infp = fopen("Section07_Data.txt","r");

  if(infp==NULL)
    return 0;

   do{
      menu();
      scanf("%d",&choice);
      switch(choice){
      case 1://Create a linked list from the file content
      head= create_LL(infp);
      printf("\n\t\t LL was created!\n");
           break;
      case 2:// add a new student to LL
      ToAdd=create_fill_node();
      add_node(&head,ToAdd);
           break;
      case 3:
      if(head==NULL)
      printf("\n\t\t LL is empty\n");
      else{
      delete_student(&head,id_tosearch);
      printf("\n\t\tInput student ID to look for: \n");
      scanf("%d",&id_tosearch);
      status=delete_student(&head,id_tosearch);
      if(status==0)
        printf("\n\t\t student with id %d was not found\n",id_tosearch);
      else
        printf("\n\t\t student with id %d was dropped\n",id_tosearch);
      }
           break;

      case 4:
        traverse_LL(head);
            break;
      case 5://count student 
        n_students=count_students(head);
        if(n_students==0)
          printf("There is no student in the LL\n");
        else
          printf("There are %d student in the LL \n",n_students);
            break;
      case 6:
          sort_students(&head);
          printf("The students were sorted regarding to their gpa successfully. \n");

            break;
      case 7:printf("\n\t\tYou decided to QUIT\n\n\t\tBYE!\n\n\t\t");
            break;
      default:printf("\n\t\tThat was an INVALID CHOICE!\n");
    }//end of switch
   }while(choice!=7);    
}
/*  Functions Definitions */
void menu(void){
  printf("\n\t\t----------------------------------------\n");
  printf("\n\t\t1. Create an Initial List\n");
  printf("\n\t\t2. Add a New Student\n");
  printf("\n\t\t3. Drop a Student\n");
  printf("\n\t\t4. Traverse LL\n");
  printf("\n\t\t5. Count Students in the LL\n");
  printf("\n\t\t6. Sort Students in the LL by CGPA\n");
  printf("\n\t\t7. Quit\n");
  printf("\n\t\t----------------------------------------\n");
  printf("\n\t\tYour choice please:");
}
void add_node_end(node**phead,node*ToAdd,node*ptail){ 
   
  if(*phead==NULL && *ptail==NULL){
     *phead=ToAdd; 
     *ptail=ToAdd;
     ToAdd->next = NULL;
  }
  else{
    (*ptail)->next=ToAdd;
     *ptail= ToAdd;

  }
}

void add_node_beg(node**phead,node*ToAdd,node*ptail){
   if(*phead==NULL && *ptail==NULL){
     *phead=ToAdd; 
     *ptail=ToAdd;
      ToAdd->next = NULL;
  }
   else{
  ToAdd->next=(*phead);
  (*phead)= ToAdd;
   }
  

}

void traverse_LL(node*head){
   node*walker=head; 
   if(head==NULL)
     printf("\n\t\tLinked list is EMPTY!\n");
   else{	    
     while(walker!=NULL){
       printf("\n\t\tStudent ID:%d\n",walker->d.id);
       printf("\n\t\tStudent Name:%s\n",walker->d.s_name);
       printf("\n\t\tMajor:%s\n",walker->d.s_major);
       printf("\n\t\tAdvisor:%s\n",walker->d.a_name);
       printf("\n\t\tCGPA:%.2f\n",walker->d.cgpa);
       printf("\n\t\t--------------------------\n");
       walker=walker->next;   
      }
   }
}

node* create_LL(FILE* infp){
  node *head=NULL,*tail=NULL, *ToAdd;
    char line[100];
    while(!feof(infp)){
      ToAdd= (node*)malloc(sizeof(node));
      //this bloch will have all the information abt student
      if (ToAdd == NULL) {
            printf("Memory allocation failed!\n");
            return head;
        }
      fscanf(infp,"%d",&ToAdd->d.id);
      getc(infp);//reading a new line
      fgets(ToAdd->d.s_name,100, infp);
      fgets(ToAdd->d.s_major,100, infp);
      fgets(ToAdd->d.a_name,100, infp);
      fscanf(infp,"%lf",&ToAdd->d.cgpa);
      getc(infp);
      fgets(line,100,infp);
      ToAdd->next=NULL;
      //node was alreadu creaaty so we call to add
      add_node(&head,&tail,ToAdd);

    }
    return(head);
}

node* create_fill_node(void){
  node *new_node;
  new_node=(node*)malloc(sizeof(node));
   if (new_node == NULL) {  // Check if malloc failed
        printf("Memory allocation failed!\n");
        return NULL;
    }

  getchar();
  printf("\n\t\tInput student id: \n");
  scanf("%d",&new_node->d.id);
  getchar();
  printf("\n\t\tInput student name: \n");
  gets(new_node->d.s_name);
  new_node->d.s_name[strcspn(new_node->d.s_name, "\n")] = '\0';  // Remove trailing newline
  printf("\n\t\tInput student major: \n");
  gets(new_node->d.s_major);
  new_node->d.s_major[strcspn(new_node->d.s_major, "\n")] = '\0';  // Remove trailing newline
  printf("\n\t\tInput advisor name: \n");
  gets(new_node->d.a_name);
  new_node->d.a_name[strcspn(new_node->d.a_name, "\n")] = '\0';  // Remove trailing newline
  printf("\n\t\tInput student %s gpa: \n",new_node->d.s_name);
  scanf("%lf",&new_node->d.cgpa);
  new_node->next=NULL;
  return(new_node);
}

int delete_student(node**phead,node**ptail,int ID){
  node* walker=(*phead),*temp;
  if((*phead)==NULL)
      *ptail==NULL;
    return -1;
  else if((*phead)->d.id==ID){
    temp=(*phead);
    *phead=(*phead)->next;
    free(temp);
    if((*phead)->next==NULL)
     *ptail=NULL;
    return 1;
  }
  else{
    while(walker->next!=NULL){
      if(walker->next->d.id==ID){
        temp=walker->next;
        walker->next=temp->next;
        if(temp->next==NULL)
         *ptail=walker;
        free(temp)
        return 1;
      }
      walker=walker->next;
    }
  }
  return 0;
}

int count_students(node*head){
  node *walker=head;
  int count=0;
  if(head==NULL){
    return 0;
  }
  else{
    while(walker!=NULL){
      count++;
      walker=walker->next;
    }
  }
  return count;
}

void swap(node* n1, node* n2){
  data temp=n1->d;
  n1->d=n2->d;
  n2->d=temp;
}
void sort_students(node**phead){
  if((*phead)==NULL){
    printf("The LL is empty\n");
    return;
  }
  else{
      for(node* walker1=*phead;walker1->next!=NULL;walker1=walker1->next){
            node*min=walker1;
            for(node*walker2=walker1->next;walker2!=NULL;walker2=walker2->next){
                 if(min->cgpa > walker2->cgpa){
                   min=walker2;
                 }
            }
            if(min!= walker1){

            swap(walker1,min);
          
  }
}
}
}

void reverse(node **phead, node **ptail) {
    node *current, *previous, *nextnode;
    current = *phead; 
    previous = NULL;   
    *ptail = *phead;   
    while (current != NULL) {
        nextnode = current->next;  // Save the next node
        current->next = previous;  // Reverse the current node's pointer
        previous = current;        // Previous moves to current node
        current = nextnode;        // Current moves to the next node in the original list
    }
    *phead = previous;  // Update head to the new first node
}

