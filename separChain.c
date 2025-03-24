// The purpose of this code
// is to show how we can use
// separate chaining to solve
// collision

#include <stdio.h>
#include <string.h>

typedef struct tag {
    char student_name[20];
    int student_id;
    struct tag* next;
} student_node;

// Functions to use
void menu(void);
void add_student(student_node**, student_node**, int);
void initialize_hash_table(student_node**,int);
void display_studentd(student_node**,int);
void check_empty_hash_table(student_node**,int);
student_node* delete_student(student_node** , int , int);
char* search_student(student_node**, int , int);
int hash_function(int, int);
student_node* create_initiliaze_node();

int main(){
student_node* hash_table[11],*node;
char name[20];
int choice, index, size, id;
size=10;
// Initializing hash table
initialize_hash_table(hash_table,size);
do {
    menu();
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            node=create_initiliaze_node();
            index=hash_function(node->student_id,size);
            add_student(hash_table,node,index);
            break;

        case 2:
            printf("You are deleting a student:\n");
            printf("Please input the student ID:\n");
            scanf("%d", &id);
            index = hash_function(id, size);
            node=delete_student(hash_table,id,index);
            if (node==NULL) {
                printf("\n\tstudent with ID: %d is not found in the Hash Table\n",id);
            } else {
                printf("\n%s with ID: %d is removed from the Hash Table!\n",node->student_name,node->student_id);
                free(node);
            }
            break;
        case 3:
            printf("Please input the student ID: ");
            scanf("%d", &id);
            index = hash_function(id, size);
            strcpu(name,search_student(hash_table,id,index));
            if (strcpy(name,"Not Found")==0) {
            printf("\n\tStudent with ID: %d is not foud in the Hash Table!\n",id);
            } else {
            printf("\nStudent %s with ID: %d is found in the Hash Table!\n",name, id);
            }   
    break;

case 4:
             display_students(hash_table, size);
    break;
case 5:
            printf("\n\tDone\n");
    break;
default:
    printf("\nWrong Choice!\n");
    }
} while (choice != 5);
}

void menu(void) {
    printf("----------Menu To Use----------\n");
    printf("1. Add a student to Hash Table\n");
    printf("2. Delete a student from Hash Table\n");
    printf("3. Search for a student in Hash Table\n");
    printf("4. Display list of students in Hash Table\n");
    printf("5. Quit\n");
    printf("Your choice: ");
}
 
student_node* delete_student(student_node** HT, int id, int index) {
    student_node *walker, *temp;

    if (HT[index] == NULL) {
        return NULL;  // No student found at this index
    }
    else{
        walker = HT[index];
        if (walker->student_id == id) {
        HT[index] = walker->next;  // Update head of the list
        return walker;
    } else {
        while (walker->next != NULL ) {
         if (walker->next->student_id == id) {
            temp = walker->next;
            walker->next = walker->next->next;  // Bypass the node
            return temp;
         } else {
            walker = walker->next;
        }
        }
        return NULL;
    }
}
}
char* search_student(student_node** HT, int id, int index) {
    student_node *walker = HT[index];

    if (walker == NULL) {
        return "not found";  // Return if no student found at this index
    } else {
        while (walker != NULL) {
            if (walker->student_id == id) {
                return walker->student_name;  // Return the name if found
            }
            else
            walker = walker->next;  // Move to the next node
        }
        return "not found";  // Return if ID not found in the list
        }
    }

void display_students(student_node** HT, int size) {
    int status,i;
    student_node*walker;
    status=check_empty_hash_table(HT, size);
    if (status==0) {
        printf("\n\nThis Hash Table is Empty!!\n");
    } else {
        printf("\n\tThis is the content of the Hash Table\n");
        for (int i = 0; i < size; i++) {
                walker=HT[i];
                while (walker != NULL) {
                    printf("\n\t%s\t%d\n", walker->student_name, walker->student_id);
                    walker = walker->next;  // Traverse the list
                }

            }
        }
    }

student_node* create_initialize_node() {
    student_node *new_node = (student_node*)malloc(sizeof(student_node));
    char temp;  // Assuming a maximum length for student names
        scanf("%c",&temp);
        printf("Enter Student Name: ");
        gets(new_node->student_name);
        printf("Enter Student ID: ");
        scanf("%d", &new_node->student_id);  // Read student ID
        new_node->next = NULL;  // Initialize next pointer
    return new_node;  // Return the created node
}

void initialize_hash_table(student_node** HT, int size) {
    for (int i = 0; i < size; i++) {
        HT[i] = NULL;  // Initialize all indices to NULL
    }
}

int hash_function(int id, int size) {
    return id % size;  // A simple modulo hash function
}

int check_empty_hash_table(student_node** HT, int size) { 
    for (int i = 0; i < size; i++) {
        if (HT[i] != NULL) {
            return 1;  // Return 1 if any index is non-NULL
        }
    }
    return 0;  // Return 0 if all indices are NULL
}