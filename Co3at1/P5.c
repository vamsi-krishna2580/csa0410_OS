#include <stdio.h>

int main() {
    int base, limit, logical, physical;

    printf("Enter base address: ");
    scanf("%d", &base);

    printf("Enter limit: ");
    scanf("%d", &limit);

    printf("Enter logical address: ");
    scanf("%d", &logical);

    if (logical >= 0 && logical < limit) {
        physical = base + logical;

        printf("\nAccess Allowed");
        printf("\nLogical Address : %d", logical);
        printf("\nPhysical Address: %d\n", physical);
    } else {
        printf("\nAccess Denied!");
        printf("\nInvalid memory address\n");
    }

    return 0;
}