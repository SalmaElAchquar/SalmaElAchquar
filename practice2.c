#include <stdio.h>
#include <string.h>
///*Write a recursive function to reverse a string.
void reverse_string(char* str, int start, int end) {
    // Base case: stop when start is greater than or equal to end
    if (start >= end)
        return;

    // Swap the characters at positions 'start' and 'end'
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    // Recursive call with next positions
    reverse_string(str, start + 1, end - 1);
}

int main() {
    char str[100];
    printf("Enter a string to reverse: ");
    scanf("%s", str);

    int length = strlen(str);
    reverse_string(str, 0, length - 1);

    printf("Reversed string: %s\n", str);
    return 0;
}
