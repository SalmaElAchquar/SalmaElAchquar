//Write a recursive function to find the minimum value in an array.
#include<stdio.h>
#include<string.h>
int find_min(int arr[], int n);
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
        int min= find_min(arr,N);
        printf("the minimum number in the array is %d",min);
    }
    else
        printf("THANK YOU!!\n");
return 0;
}
int find_min(int arr[], int n) {
    if (n == 1)
        return arr[0];
    int min = find_min(arr, n - 1);  
    if (arr[n - 1] < min)
        return arr[n - 1];
    else
        return min;
}
/*
Step-by-Step Trace:
We will now trace how the function behaves when we call find_min(arr, 5).

First Call: find_min(arr, 5)
Condition Check: n == 1? No, because n = 5.
Recursive Call: min = find_min(arr, 4).
Second Call: find_min(arr, 4)
Condition Check: n == 1? No, because n = 4.
Recursive Call: min = find_min(arr, 3).
Third Call: find_min(arr, 3)
Condition Check: n == 1? No, because n = 3.
Recursive Call: min = find_min(arr, 2).
Fourth Call: find_min(arr, 2)
Condition Check: n == 1? No, because n = 2.
Recursive Call: min = find_min(arr, 1).
Fifth Call: find_min(arr, 1)
Condition Check: n == 1? Yes, because n = 1.
Return: arr[0], which is 12. This is the base case, so the function returns 12.
Returning from the Recursion:
Now, the function returns back up the call stack, with each call checking the minimum 
between the returned value and the current element.
Returning to Fourth Call: find_min(arr, 2)
Returned Value: min = 12 from the previous call (find_min(arr, 1)).
Compare: Is arr[1] (which is 3) less than min (which is 12)? Yes.
Return: 3.
Returning to Third Call: find_min(arr, 3)
Returned Value: min = 3 from the previous call (find_min(arr, 2)).
Compare: Is arr[2] (which is 15) less than min (which is 3)? No.
Return: 3.
Returning to Second Call: find_min(arr, 4)
Returned Value: min = 3 from the previous call (find_min(arr, 3)).
Compare: Is arr[3] (which is 7) less than min (which is 3)? No.
Return: 3.
Returning to First Call: find_min(arr, 5)
Returned Value: min = 3 from the previous call (find_min(arr, 4)).
Compare: Is arr[4] (which is 9) less than min (which is 3)? No.
Return: 3.
Final Result:
The minimum value in the array is 3.


*/