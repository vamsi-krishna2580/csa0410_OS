#include <stdio.h>

int main() {
    int pages, pageSize, page, offset;
    int pageTable[100];
    int frame, physical;

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    printf("Enter page size: ");
    scanf("%d", &pageSize);

    printf("Enter page table:\n");

    for (int i = 0; i < pages; i++) {
        printf("Page %d -> Frame: ", i);
        scanf("%d", &pageTable[i]);
    }

    printf("Enter page number: ");
    scanf("%d", &page);

    printf("Enter offset: ");
    scanf("%d", &offset);

    if (page >= 0 && page < pages && offset >= 0 && offset < pageSize) {
        frame = pageTable[page];
        physical = frame * pageSize + offset;

        printf("\nPage Number     = %d", page);
        printf("\nFrame Number    = %d", frame);
        printf("\nOffset          = %d", offset);
        printf("\nPhysical Address = %d\n", physical);
    } else {
        printf("Invalid page number or offset\n");
    }

    return 0;
}