/*Library Management System Application
You are asked to develop a library management system for AUI’s M6L. The library has a collection of books that a patron (students/faculty or staff) can borrow. Each book has a unique identifier, a title, and an associated borrowing status. The library offers three types of books:
Regular Books (Type 'R'): These are standard books that can be borrowed for 14 days. There are 50 regular books available with a 10 dhs/day late fee.
Reference Books (Type 'F'): These are reference materials that patrons can use only within the library premises and cannot be taken home. There are 20 reference books available with a 15 dhs/day late fee.
Special Collection Books (Type 'S'): These are rare and valuable books that can be borrowed for 7 days. However, patrons need special permission to borrow these books, and there are only 10 available with a 20 dhs/day late fee.
When the application is started, it waits for the user to type something:
'B' or 'b' when a patron wants to borrow a book.
'R' or 'r' when a patron wants to return a book.
'Q' or 'q' to quit and exit.
Once the operator chooses to borrow or return a book, the application asks for the patron's library ID number. If the ID number is valid, the application proceeds with the borrowing or returning process. The borrowing process includes checking the availability of the book, updating the book's status, and calculating any fines if the book is returned late. The returning process involves updating the book's status and notifying the patron if there are fines.
Using a top-down design approach:
Identify all the needed constants and give their respective preprocessor directives.
Identify all the needed global variables and give their respective declarations.
Identify the content of the C header file (name it header.h)
Draw the flowchart of the high-level algorithm (main only)
Identify the content of the main program (name it main.c)
At this point, can we compile the main file? Justify your answer and give the corresponding gcc command if this is possible. 
Define all the declared functions, name it library.c
What commands are needed to link, load and execute the whole application?*/
#include<stdio.h>
#include "library.h"
int main(void){
int ID;
char choice;
int status=0;
 
  do {
     choice = menu();
     printf("Pleas enter your ID");
    scanf("%d",&ID);
if(choice=='B'){
  int x;
  handle_choiceB(status);
    status =1 ;
 }
else if(choice=='R'){
      status = handle_choiceR(status);
}
else if( choice!= 'Q')
   printf("You entered the wrong choice\n");
 }while( choice != 'Q' );

return 0;
}

