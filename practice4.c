//Write a recursive function to check if an array is sorted in ascending order.
#include<stdio.h>
#include<string.h>
int is_sorted(int arr[], int n);
void fill_array(int arr[],int num){
    for(int i=0; i< num;i++){
        printf(" please enter the %d number : ",i+1);
        scanf("%d",&arr[i]);
    }
}
int main(){
    char choice[4];
    int N,to_look,found;
    printf("Please enter YES/NO if you want to try : \n");
    scanf("%3s",choice);
    if(strcmp(choice, "YES") == 0){
        printf("please enter the number of numbers you want to have : \n");
        scanf("%d",&N);
        int arr[N];
        fill_array(arr,N);
        int found= is_sorted(arr,N-1);
        if(found==1)
            printf("The array is sorted \n");
        if(found==0)
            printf("The array is not sorted\n");
    }
    else
        printf("THANK YOU!!\n");
return 0;
}
int is_sorted(int arr[], int n){
    if(n==0)
        return 1;
    if(arr[n-1]>arr[n])
        return 0;
    return is_sorted(arr,n-1);
}