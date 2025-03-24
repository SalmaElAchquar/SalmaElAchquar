#include<stdio.h>
#include<stdlib.h>
#define MAX_DAYS 14 
#define LATE_FEE 10 

char menu() {
    char choice;
    printf("please enter 'B' if you want to borrow a book\n"
       " 'R' if you want to return a book\n"
        "'Q' if you want to quit\n ");
        scanf(" %c", &choice);
        return choice;
}
void handle_choiceB(int status){
    if(status==0){
      printf("you seccessfully borrowed the book\n");
      status = 1;
      }
    else if (status ==1)
      printf("the book is not available\n");
}
 int handle_choiceR(int status){
int late,days, late_fees;
    if(status == 1){
        printf("you successfully returned the book\n");
        status = 0;
        printf("for how long did you borrowed the book: ");
        scanf("%d",&days);
          if( days> MAX_DAYS){
            late= days - MAX_DAYS;
            late_fees= late * LATE_FEE;
            //getchar();
            printf("you have a fine of %d dhs",late_fees);
          }
          else 
          printf(" Thank you for returning the book in time");
          return status;
       }
        else
        printf("you didn't borrow any book\n");
        return 0;
}
      

