/*Write a recursive function to calculate the factorial of a given number n.*/
/*Write a recursive function to find the sum of the digits of a given number.*/
//Write a recursive function to calculate the value of a^b.




#include<stdio.h>
int sum_digits(int num);
int factorial(int n);
int power(int a, int b);
int main(){
    int num,fact,result,number;
   
    printf("Please enter a number to compute its factorial: \n");
    scanf("%d",&num);
    fact=factorial(num);
    printf("%d is the factorial of %d",fact,num);
    printf("\nPlease enter a number to calculate the sum of its digits :\n");
    scanf("%d",&number);
    result = sum_digits(number);
    printf("The sum of the digits of %d is %d.\n", number, result);
    printf("Please enter a number and ist power :");
    scanf("%d%d",&a,&b);
    pow=power(a,b);
    printf("%d power of %d id %d",a,b,pow);
    return 0;
    }
    int factorial(int n){
            if(n==1)
                return 1;
            return(n*factorial(n-1));
    }
    int sum_digits(int n){
        if (n == 0)
        return 0;
    return (n % 10) + sum_digits(n / 10);
    }
    int power(int a,int b){
        if(b==0)
            return (1);
        return a*func(a,b-1);
    }