#include<stdio.h>
#define REGULAR 30
#define TERRASSE 10
#define SUITS 10
#define P_REGULAR 300
#define P_TERRASSE 400
#define P_SUITS 500
 int meal_type(char menu);
int room_type(char type, int nights);
int regular=30, terrasse = 10 , suits= 10;
void menu(){
 printf("There are 50 rooms in our hotel\n : ");
 printf(" %d regular rooms,%d of wich are  available\n",REGULAR, regular);
 printf("%d with a terrasse, %d of which are available\n",TERRASSE,terrasse);      
 printf( "%d and 10 are suits, %d of which are available\n ",SUITS,suits );
 printf("there are two restaurants in our hotel\n : "
                "the first one serving Moroccan cuisine\n"
                " the second one Spanish & Portuguese\n");
}

int handle_choice(char choice) {
    char type, menu;
    int total_price, x,y;

    switch(choice) {
        case 'B':
            printf("Please enter 1 for regular, 2 for terrasse, or 3 for suits: ");
            scanf(" %c", &type);
            printf("Please enter how many nights you want to book: ");
            int nights;
            scanf("%d", &nights);
            x = room_type(type, nights);
            break;
        case 'R':
            printf("Please enter 1 for Moroccan cuisine or 2 for Spanish & Portuguese: ");
            scanf(" %c", &menu);
            y = meal_type(menu);
            break;
        case 'Q':
            printf("Thank you for using our hotel management system.\n");
            break;
        default:
            printf("Sorry, you entered the wrong choice.\n");
    }
        total_price= x+y;
    return total_price;
}
      
        int room_type(char type, int nights){
          int  total_amount=0 ,price ;
         switch(type){
                    case '1':
                      if( regular > 0){
                         printf("You successfully booked the room!");
                        price = P_REGULAR * nights;
                       
                        regular--;
                      }
                      else
                         printf("The number of rooms is not available please check availablities");
                      break;
                    case '2':
                       if(terrasse > 0){
                         printf("You successfully booked the room!");
                          price = P_TERRASSE * nights;
                          terrasse--;
                          
                       }
                       else
                         printf("The number of rooms is not available please check availablities");
                    break;
                  case '3':
                        if( suits > 0){
                         printf("You successfully booked the room!");
                         price = P_SUITS * nights;
                        
                         suits--;
                        }
                       else
                         printf("The number of rooms is not available please check availablities");
                    break;
                  default:
                        printf("you entered the wrong digit");
        
    }
               total_amount+=price;
     return total_amount;
              
 }
        int meal_type(char menu){
            int num,fees, total,total_meal = 0;
            switch(menu){
            case '1':
              printf("please enter the number of customers who chose the full course");
              scanf("%d",&num);
              printf ("please enter any additional fees");
              scanf("%d",&fees);
              total= (num * 250) + fees;
            break;
            case '2':
            printf("please enter the number of customers who chose the full course");
              scanf("%d",&num);
              printf ("please enter any additional fees");
              scanf("%d",&fees);
              total= (num * 300) + fees;
            break;
            default:
            printf("You entered the wrong digit.\n");
            }
         return total_meal += total;
 }
    
        
        

