#include <stdio.h>

int main() {
    int users, files;

    printf("Enter number of users: ");
    scanf("%d", &users);

    for (int i = 0; i < users; i++) {
        printf("User %d\n", i + 1);

        printf("Enter number of files: ");
        scanf("%d", &files);

        char file[20];

        for (int j = 0; j < files; j++) {
            printf("File %d: ", j + 1);
            scanf("%s", file);
        }
    }

    return 0;
}