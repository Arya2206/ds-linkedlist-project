#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollNo;
    char name[50];
    float marks;
    struct Student* next;
};

struct Student* head = NULL;

// Insert a student
void insertStudent(int rollNo, char name[], float marks) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    newStudent->rollNo = rollNo;
    strcpy(newStudent->name, name);
    newStudent->marks = marks;
    newStudent->next = NULL;

    if (head == NULL) {
        head = newStudent;
    } else {
        struct Student* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newStudent;
    }
    printf("Student inserted.\n");
}

// Display students
void display() {
    struct Student* temp = head;
    if (temp == NULL) {
        printf("No student records found.\n");
        return;
    }
    printf("\nStudent Records:\n");
    while (temp != NULL) {
        printf("Roll No: %d, Name: %s, Marks: %.2f\n", temp->rollNo, temp->name, temp->marks);
        temp = temp->next;
    }
}

// Delete a student
void deleteStudent(int rollNo) {
    struct Student* temp = head;
    struct Student* prev = NULL;

    while (temp != NULL && temp->rollNo != rollNo) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Student not found.\n");
        return;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    free(temp);
    printf("Student deleted.\n");
}

// Update student record
void updateStudent(int rollNo, char name[], float marks) {
    struct Student* temp = head;
    while (temp != NULL) {
        if (temp->rollNo == rollNo) {
            strcpy(temp->name, name);
            temp->marks = marks;
            printf("Student updated.\n");
            return;
        }
        temp = temp->next;
    }
    printf("Student not found.\n");
}

// Sort by marks (bubble sort)
void sortByMarks() {
    struct Student *i, *j;
    int tempRoll;
    char tempName[50];
    float tempMarks;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->marks > j->marks) {
                // swap data
                tempRoll = i->rollNo;
                strcpy(tempName, i->name);
                tempMarks = i->marks;

                i->rollNo = j->rollNo;
                strcpy(i->name, j->name);
                i->marks = j->marks;

                j->rollNo = tempRoll;
                strcpy(j->name, tempName);
                j->marks = tempMarks;
            }
        }
    }
    printf("Sorted by marks.\n");
}

// Sort by name
void sortByName() {
    struct Student *i, *j;
    int tempRoll;
    char tempName[50];
    float tempMarks;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (strcmp(i->name, j->name) > 0) {
                // swap data
                tempRoll = i->rollNo;
                strcpy(tempName, i->name);
                tempMarks = i->marks;

                i->rollNo = j->rollNo;
                strcpy(i->name, j->name);
                i->marks = j->marks;

                j->rollNo = tempRoll;
                strcpy(j->name, tempName);
                j->marks = tempMarks;
            }
        }
    }
    printf("Sorted by name.\n");
}

// Main menu
int main() {
    int choice, rollNo;
    char name[50];
    float marks;

    do {
        printf("\n1. Insert\n2. Delete\n3. Update\n4. Display\n5. Sort by Marks\n6. Sort by Name\n0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter Roll No, Name, Marks: ");
                scanf("%d %s %f", &rollNo, name, &marks);
                insertStudent(rollNo, name, marks);
                break;
            case 2:
                printf("Enter Roll No to delete: ");
                scanf("%d", &rollNo);
                deleteStudent(rollNo);
                break;
            case 3:
                printf("Enter Roll No, New Name, New Marks: ");
                scanf("%d %s %f", &rollNo, name, &marks);
                updateStudent(rollNo, name, marks);
                break;
            case 4:
                display();
                break;
            case 5:
                sortByMarks();
                break;
            case 6:
                sortByName();
                break;
            case 0:
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}