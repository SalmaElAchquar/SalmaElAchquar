//Code done by: ..........(write your name)
//When you see in a comment "-->HM" that means Homework
//------------------------------------------

#include<stdio.h>


/*       User Defined Functions       */
//-->HM: you will have to fill in these prototypes
//For each function declaration, fill in the arguments data types
void menu(void); 
void fill_arrays();
void print_arrays_content(); 
double search_student_earned_credits();
void sort_students_by_credits();
void swap();

/*         Main Function        */
int main(void){
   //I am assuming that I have 35 students
   //For testing, we will work with n_students	 
   int IDs[35],Credits[35];
   int choice,n_students; 
   
   do{
   	  //call menu function 
      menu();
      scanf("%d",&choice);
      switch(choice){
	    case 1:printf("\n\t\tInput the number of students:");
		       scanf("%d",&n_students);
			   //-->HM: call fill function and check if it is working   
		       break;
	    case 2://-->HM Call the appropriate Function
		       break;
	    case 3://-->HM Call the appropriate Function
		       break;
	    case 4://-->HM Call the appropriate Function
		       break;
	    case 5:printf("\n\t\tYou decided to QUIT\n\n\t\tBYE!\n\n\t\t");
               break;
	    default:printf("\n\t\tThat was an INVALID CHOICE!\n");
	  }//end of switch
   }while(choice!=5);    
}
/*  Functions Definitions */
void menu(void){
  printf("\n\t\t----------------------------------------\n");
  printf("\n\t\t1. Fill Arrays\n");
  printf("\n\t\t2. Display Array Content\n");
  printf("\n\t\t3. Sort Students By Credits\n");
  printf("\n\t\t4. Get a Student's Number of Credits\n");
  printf("\n\t\t5. Quit\n");
  printf("\n\t\t----------------------------------------\n");
  printf("\n\t\tYour choice please:");
}
//-->HM: Define the remaining functions
