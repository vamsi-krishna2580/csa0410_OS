#include <stdio.h>
#include <string.h>

struct User
{
    char username[30];
    char files[20][30];
    int fileCount;
};

int main()
{
    struct User user[10];
    int users = 0;
    int choice, i, j, found;
    char uname[30], fname[30];

    while (1)
    {
        printf("\n--- TWO LEVEL DIRECTORY ---");
        printf("\n1. Create User Directory");
        printf("\n2. Create File");
        printf("\n3. Display Directory");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter username: ");
                scanf("%s", user[users].username);
                user[users].fileCount = 0;
                users++;
                printf("User directory created\n");
                break;

            case 2:
                printf("Enter username: ");
                scanf("%s", uname);

                found = -1;

                for (i = 0; i < users; i++)
                {
                    if (strcmp(user[i].username, uname) == 0)
                    {
                        found = i;
                        break;
                    }
                }

                if (found == -1)
                {
                    printf("User not found\n");
                }
                else
                {
                    printf("Enter file name: ");
                    scanf("%s", fname);

                    strcpy(user[found].files[user[found].fileCount], fname);
                    user[found].fileCount++;

                    printf("File created successfully\n");
                }
                break;

            case 3:
                for (i = 0; i < users; i++)
                {
                    printf("\nUser: %s\n", user[i].username);

                    for (j = 0; j < user[i].fileCount; j++)
                        printf("   %s\n", user[i].files[j]);
                }
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}