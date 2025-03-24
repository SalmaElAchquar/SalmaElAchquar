#include <stdio.h>
#include <string.h>
#include <ctype.h>

int enqueue(char *queue, int* rear, int size, char toEnqueue, int* front) {
    // Check if queue is full
    if ((*front == -1) && (*rear == -1)) { // Empty queue
        *front = *rear = 0;
        queue[*rear] = toEnqueue;
        return 1;
    } else if ((((*rear) + 1) % size) == *front) { // Queue full
        return 0;
    } else {
        *rear = ((*rear) + 1) % size;
        queue[*rear] = toEnqueue;
        return 1;
    }
}

void dequeue(char *queue, int* rear, int* front, int size) {
    if ((*front == -1) && (*rear == -1)) {
        printf("The queue is empty\n");
    } else if (*front == *rear) {
        *front = *rear = -1; // Queue is empty now
    } else {
        *front = ((*front) + 1) % size;
    }
}

int is_palindrome(char *str, int size) {
    char queue[size];
    int front = -1, rear = -1;

    // Step 1: Enqueue all characters of the string to the queue
    for (int i = 0; str[i] != '\0'; i++) {
        enqueue(queue, &rear, size, str[i], &front);
    }

    // Step 2: Check if the characters form a palindrome
    for (int i = 0; i < strlen(str) / 2; i++) {
        if (queue[front] != queue[rear]) {
            return 0; // Not a palindrome
        }

        // Dequeue from front and rear
        dequeue(queue, &rear, &front, size);
    }

    return 1; // It's a palindrome
}

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);  // Get input string
    str[strcspn(str, "\n")] = '\0';  // Remove the trailing newline character

    // Convert the string to lowercase to ignore case sensitivity
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }

    int size = 100;  // Set the queue size

    if (is_palindrome(str, size)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
