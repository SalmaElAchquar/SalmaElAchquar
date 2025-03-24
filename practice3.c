//Write a recursive function to perform a binary search on a sorted array.
#include<stdio.h>
#include<string.h>
int search(int arr[], int low, int high, int key);
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
        printf("Please enter the number you want to look for :\n");
        scanf("%d",&to_look);
        int found= search(arr,0,N-1,to_look);
        if(found==1)
            printf("The  element is found in the array \n");
        if(found==0)
            printf("Not found\n");
    }
    else
        printf("THANK YOU!!\n");
return 0;
}
int search(int arr[], int low, int high, int key){
    if(arr[low]>=arr[high]&& arr[low]!=key)
        return 0;
    if(arr[low]==key|| arr[high]==key)
        return 1;
     search(arr,low+1,high-1,key);
}
//binary search
int binary_search(int arr[], int low, int high, int key) {
    if (low > high) {
        return 0;
    }
    int mid = (low + high) / 2;
    if (arr[mid] == key) {
        return 1; 
    } else if (key < arr[mid]) {
        return binary_search(arr, low, mid - 1, key); /
    } else {
        return binary_search(arr, mid + 1, high, key);
    }
}