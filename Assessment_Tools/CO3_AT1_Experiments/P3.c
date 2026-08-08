#include <stdio.h>

int main() {
    int n, pageSize, pageTable[100];
    int logical, page, offset, frame, physical;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page size: ");
    scanf("%d", &pageSize);

    printf("Enter page table entries:\n");

    for (int i = 0; i < n; i++) {
        printf("Page %d -> Frame: ", i);
        scanf("%d", &pageTable[i]);
    }

    printf("\nEnter logical address: ");
    scanf("%d", &logical);

    page = logical / pageSize;
    offset = logical % pageSize;

    if (page >= n) {
        printf("Invalid logical address\n");
        return 0;
    }

    frame = pageTable[page];
    physical = frame * pageSize + offset;

    printf("\nLogical Address : %d", logical);
    printf("\nPage Number     : %d", page);
    printf("\nOffset          : %d", offset);
    printf("\nFrame Number    : %d", frame);
    printf("\nPhysical Address: %d\n", physical);

    return 0;
}