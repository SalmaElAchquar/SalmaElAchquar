#include<stdio.h>
#include<string.h>
int check_palindrome(char *toCheck, int start, int end);
int main() {
    char number_to_check[20];
    int status;
    char answer[4];

    do {
        printf("\n\tInput a number to check: ");
        scanf("%s", number_to_check);

        status = check_palindrome(number_to_check, 0, strlen(number_to_check) - 1);

        if (status == 1)
            printf("\n\t%s is a palindrome number!\n", number_to_check);
        else
            printf("\n\t%s is not a palindrome number!\n", number_to_check);

        printf("\n\t---------------------------------------------------\n");
        printf("\n\tTry another word? YES/NO: ");
        scanf("%s", answer);

    } while (strcmp(answer, "NO") != 0);

    return 0;
}
int check_palindrome(char *toCheck, int start, int end) {
    
    if (start >= end) 
        return 1;
    if (toCheck[start] != toCheck[end]) 
        return 0;
    return check_palindrome(toCheck, start + 1, end - 1);
}

/*
 Input "121"
Initial Call: check_palindrome("121", 0, 2)

Step-by-Step Trace:
First Call:

start = 0, end = 2
Compare toCheck[0] ('1') with toCheck[2] ('1'). Match.
Recursive call: check_palindrome("121", 1, 1).
Second Call:

start = 1, end = 1
start >= end, so return 1  (base case).
Backtracking:

The second call returns 1 to the first call.
The first call also returns 1.
Final Result: The input "121" is a palindrome.*/

//2nd code
#include <stdio.h>

// Helper function to reverse the digits of a number recursively
int reverse_number(int num, int rev) {
    if (num == 0) // Base case: if the number is fully processed
        return rev;
    return reverse_number(num / 10, rev * 10 + num % 10);
}

// Function to check if a number is a palindrome
int is_palindrome(int num) {
    if (num < 0) // Negative numbers are not palindromes
        return 0;
    int reversed = reverse_number(num, 0); // Reverse the number
    return num == reversed; // Compare the original and reversed numbers
}

int main(void) {
    int num;

    printf("Enter a number to check if it is a palindrome: ");
    scanf("%d", &num);

    if (is_palindrome(num))
        printf("%d is a palindrome.\n", num);
    else
        printf("%d is not a palindrome.\n", num);

    return 0;
}