#include <stdio.h>

int main() {
    float tlb, memory, hit;
    float withoutTLB, withTLB;

    printf("Enter TLB lookup time: ");
    scanf("%f", &tlb);

    printf("Enter memory access time: ");
    scanf("%f", &memory);

    printf("Enter TLB hit ratio (0 to 1): ");
    scanf("%f", &hit);

    withoutTLB = 2 * memory;

    withTLB = hit * (tlb + memory)
            + (1 - hit) * (tlb + 2 * memory);

    printf("\nWithout TLB EAT = %.2f", withoutTLB);
    printf("\nWith TLB EAT    = %.2f\n", withTLB);

    return 0;
}