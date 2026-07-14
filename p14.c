#include <stdio.h>

int main() {
    int n;
    char file[20][20];

    printf("Number of files: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("File %d: ", i + 1);
        scanf("%s", file[i]);
    }

    printf("\nFiles in Directory:\n");

    for (int i = 0; i < n; i++)
        printf("%s\n", file[i]);

    return 0;
}