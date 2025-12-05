#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STUDENT_FILE      "students.txt"
#define CREDENTIALS_FILE  "credentials.txt"

struct Student {
    int roll;
    char name[50];
    float marks;
};

char currentRole[10];
char currentUser[50];

/* --------- Function Prototypes --------- */
int loginSystem(void);
void mainmenu(void);
void adminMenu(void);
void userMenu(void);
void staffMenu(void);
void guestMenu(void);

void addStudent(void);
void viewStudents(void);
void searchStudent(void);
void updateStudent(void);
void deleteStudent(void);

int main(void) {
    if (loginSystem()) {
        mainmenu();
    } else {
        printf("\nAccess Denied. Exiting the system...\n");
    }
    return 0;
}


int loginSystem(void) {
    char username[50], password[50];
    char fileUser[50], filePass[50], fileRole[10];

    printf("----- LOGIN -----\n");
    printf("Username: ");
    scanf("%49s", username);
    printf("Password: ");
    scanf("%49s", password);

    FILE *fp = fopen(CREDENTIALS_FILE, "r");
    if (!fp) {
        printf("Error: %s not found!\n", CREDENTIALS_FILE);
        return 0;
    }

    /* Read username, password, role from file */
    while (fscanf(fp, "%49s %49s %9s", fileUser, filePass, fileRole) == 3) {
        if (strcmp(username, fileUser) == 0 &&
            strcmp(password, filePass) == 0) {

            strcpy(currentRole, fileRole);
            strcpy(currentUser, fileUser);
            fclose(fp);
            return 1;   // login success
        }
    }

    fclose(fp);
    printf("Invalid username or password.\n");
    return 0; // login failed
}

void mainmenu(void) {
    if (strcmp(currentRole, "admin") == 0 ||
        strcmp(currentRole, "ADMIN") == 0) {

        adminMenu();
    } else if (strcmp(currentRole, "USER") == 0) {
        userMenu();
    } else if (strcmp(currentRole, "STAFF") == 0) {
        staffMenu();
    } else {
        guestMenu();
    }
}

void adminMenu(void) {
    int choice;
    do {
        printf("\n----- ADMIN MENU -----\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Students\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                printf("Logging out...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
}

/* ------- Dummy implementations (stubs) ------- */
/* Replace these with your real code */

void addStudent(void) {
    printf("addStudent() called.\n");
}

void viewStudents(void) {
    printf("viewStudents() called.\n");
}

void searchStudent(void) {
    printf("searchStudent() called.\n");
}

void updateStudent(void) {
    printf("updateStudent() called.\n");
}

void deleteStudent(void) {
    printf("deleteStudent() called.\n");
}

void userMenu(void) {
    printf("USER menu (not implemented yet).\n");
}

void staffMenu(void) {
    printf("STAFF menu (not implemented yet).\n");
}

void guestMenu(void) {
    printf("GUEST menu (not implemented yet).\n");
}