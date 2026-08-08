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
        printf("Valid address\n");
        printf("Physical Address = %d\n", physical);
    } else {
        printf("Invalid address - Address exceeds limit\n");
    }

    return 0;
}