#include <stdio.h>
#include <string.h>

#define MAX_N_PERSON 10  // Maximum number of persons in the hash table

typedef struct {
    int id;           // Person ID
    char name[20];   // Person name
    int status;      // Status field (could represent active/inactive)
} person;

// User-defined function prototypes
void menu();
int hash1( int);
int hash2( int);
int delete_person(person*, int, int,int*);
int search_person(person*, int, int, int,int*);
void add_person(person*,person,int,int*);
void print_hash_table(person*,int)
void Initiliaze_HT(person*);
int corles=0;//you can change this variable to 1 if you want to use double hashing
int main() {
    person HashTable[MAX_N_PERSON],NewPerson;  // Declare a hash table for persons
    int choice, id, status, position,index, n_persons=0;
    char temp;
    initialize_hash_table(HashTable);  // Initialize the hash table
    do{
        menu();
        scanf("%d", &choice);  // Get user choice

        switch (choice) {
            case 1:  // Add Person
                printf("Input the person's ID: ");
                scanf("%d", &id);
                printf("Input the person's status: ");
                scanf("%d", &status);
                // Call function to add person (implementation assumed)
                break;
            case 2:  // Delete Person
                printf("Input the ID of the person to delete: ");
                scanf("%d", &id);
                // Call function to delete person (implementation assumed)
                break;
            
            case 3:  // Search Person
                printf("\n\nPlease input the person ID: ");
                scanf("%d", &id);
                index=hash1(id);
                status = search_person(HashTable, id,n_persons,index,&position);  // Search for the person
                if (status == 3)
                    printf("\nSorry, Hash Table is EMPTY.\n");
                else if(status==1)
                    printf("\nStudent with ID %d is located at index %d in the Hash Table.\n", id, position);
                else
                    printf("\n\tSorry the student is not found in the Hash Table\n");
                break;

            case 4:  // Print Hash Table
                print_hash_table(HashTable,n_persons);  // Call function to print the hash table
                break;
            case 5:
                printf("\n\tBYE!\n");
                break;
            default:
                printf("INVALID CHOICE!!!\n");
               
        }
    }while (choice != 5);
}

void Initialize_HT(person *HT) {
    for (int i = 0; i <10; i++) {  // Loop through each entry in the hash table
        HT[i].status = 0;  // Initialize the status to indicate an empty slot
        strcpy(HT[i].name, "nothing");  // Set the default name
        HT[i].id=0;
    }
}

int add_person(person *HT, person ToAdd, int location, int *n_persons) {
    int i=1,h1_location=location;
    if (*n_persons >= MAX_N_PERSON)  // Check if the table is full
        return 2;  // Return an error code

    while (HT[location].status != 1) { 
         if(colres==1)
            location = (location + 1) % tableSize;  // Linear probing
         else{
            location=(h1_location +i*hash2(Toadd.id))%tableSize;
            i++;
         }
    }
     strcpy(HT[location].name, ToAdd.name);  
     HT[location].id = ToAdd.id; 
     HT[location].status = 1;
    (*n_persons)++;  
    printf("%s is at index %d in HashTable.\n", ToAdd.name, location);
    return 1;  
}

int hash1(int id,int tablesize) {
    return (id % tablesize);  // Hash function to determine index based on ID
}

int hash2(int id) {
    return ((5 - (id % 5)));  // Secondary hash function for double hashing
}

int delete_person(person **HT, int location, int id, int *n_persons) {
   int n_tries=0,flag=0,i=1,h1_location=location;
   if(*n_persons==MAX_N_PERSON)
    return 3;
    while (HT[location].status != 0 && n_tries < tableSize) {  // Loop until an empty slot is found or tries exceed table size
        if (HT[location].id == id) {  // If the ID matches
            HT[location].id = 0;  // Mark the slot as empty
            strcpy(HT[location].name, "nothing");  // Reset name
            Ht[location].status=-1;
            (*n_persons)--;
            flag = 1;  // Indicate that deletion was successful
            break;  // Exit the loop
        } else {
           if(corles==0)
            location=(location+1)%size;
            else{
            location = (h1_location+i*hash2(id)) % tablesize;  // Recompute location
            i++;  
        }
        n_tries++;
        }
    }
    if(flag)
        return 1;
    else
        return 0;
}

void printHashTable(person* HT, int nPersons) {
    int i;
    if (n_persons == 0) {
        printf("\n\tEMPTY Hash Table!\n");
        return;
    }

    printf("\n\t Hash Table contains the following:\n");
    printf("\n\tPerson Id    |  Name\n")
    for (i = 0; i < tableSize; i++) {
        if (HT[i].status == 1) {
            printf("ID: %d Name: %s\n", HT[i].id, HT[i].name);
        }
    }
}

int search(person* HT, int id, int n_persons, int location, int*position) {
    int i = 1, n_tries = 0,flag=0,h1_location=location;
    if(n_persons==0)
        return (3);
    while (HT[location].status != 0 && n_tries <= tableSize) {
        if (HT[location].id == id) {
            *position = location;
            flag=1;
            break;
        } else {
            if (colres == 0) {
                location = (location + 1) % tableSize;
            } else {
                location = (location + i*hash2(id)) % tableSize;
                i++;
            }
        n_tries++;
        }
        
    }

    if (flag) 
        return 1;
    else
        return 0;
}