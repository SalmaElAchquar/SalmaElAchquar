#include<stdio.h>
#include "hotel.h"
int main(void){
    char choice;
    int total = 0;
    do{
        menu();
        printf("please enter B if you want to book a room\n"
        " R if you want to book a meal \n "
        " or Q if you want to quit\n");
        scanf(" %c",&choice);
        total += handel_choice(choice);
        printf("you total price of rooms and restaurants is %d\n :",total);
    } while(choice != 'Q');
return 0;
}
