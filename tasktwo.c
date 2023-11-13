#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h> // Include ctype.h for tolower function

#define MAX_USERS 10
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

typedef struct
{
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int isActive; // 0 for false (inactive), 1 for true (active)
} User;

union UserInfo {
    User user;
    int flag; // 0 for false (inactive), 1 for true (active)
};

User users[MAX_USERS];
int userCount = 0;

// Function to convert string to lowercase
void toLowercase(char *str)
{
    for (int i = 0; str[i]; i++)
    {
        str[i] = tolower(str[i]);
    }
}

void registerUser()
{
    if (userCount < MAX_USERS)
    {
        printf("Enter a username: ");
        scanf("%s", users[userCount].username);
        printf("Enter a password: ");
        scanf("%s", users[userCount].password);

        char userActiveInput[10];
        printf("Enter user active status (true/false or 0/1): ");
        scanf("%s", userActiveInput);

        toLowercase(userActiveInput);

        if (strcmp(userActiveInput, "true") == 0 || strcmp(userActiveInput, "1") == 0)
        {
            users[userCount].isActive = 1;
        }
        else if (strcmp(userActiveInput, "false") == 0 || strcmp(userActiveInput, "0") == 0)
        {
            users[userCount].isActive = 0;
        }
        else
        {
            printf("Invalid input for active status. Defaulting to inactive.\n");
            users[userCount].isActive = 0;
        }

        userCount++;
        printf("User registered successfully!\n");
    }
    else
    {
        printf("Maximum number of users reached.\n");
    }
}

void loginUser()
{
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++)
    {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0)
        {
            printf("Login successful!\n");
            printf("User active status: %s\n", users[i].isActive ? "Active" : "Inactive");
            return;
        }
    }
    printf("Login failed.\n");
}

int main()
{
    int choice;
    do
    {
        printf("Menu:\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            registerUser();
            break;
        case 2:
            loginUser();
            break;
        case 3:
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 3);

    return 0;
}
