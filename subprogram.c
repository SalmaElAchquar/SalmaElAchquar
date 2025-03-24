#include <stdio.h>
#define PRICE_TSHIRT 40
#define PRICE_SHOES 50
#define PRICE_SHIRT 45
#define QUANT_TSHIRT 7
#define QUANT_SHOES 9
#define QUANT_SHIRT 10 
void menu(){
    printf("the price of t-shirt is %d and the quantity is %d\n", PRICE_TSHIRT,QUANT_TSHIRT);
    printf("the price of shoes is %d and the quantity is %d \n",PRICE_SHOES,QUANT_SHOES);
    printf("the price of shirts is %d and the quantity is %d\n", PRICE_SHIRT, QUANT_SHIRT);
}
 float handle_choice (){
    char choice;
    int total_price=0, quant, price;
     do {
        printf("Please enter 1 for t-shirt\n"
      " 2 foe shoes \n"
      " 3 for shirts \n"
      " or 0 if you want to quite \n");
     scanf(" %c",&choice); 
     switch(choice){
        case '1' : 
        printf("please enter the quantity you want to buy : \n");
        scanf("%d",&quant);
            price = PRICE_TSHIRT * quant;
        break;
        case '2' : 
        printf("please enter the quantity you want to buy : \n");
        scanf("%d",&quant);
            price = PRICE_SHOES * quant;
        break;
        case '3' :
        printf("please enter the quantity you want to buy : \n");
        scanf("%d",&quant);
            price = PRICE_SHIRT * quant;
        break;
        case '0':
        printf("Thank you for ordering, you can quit");
        break;
        default :
        printf(" Sorry, you entered an invalid choice\n");
        continue;
     }
        total_price += price;
     } while(choice != '0');
     return (float)total_price;
     }
     