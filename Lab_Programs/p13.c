#include <stdio.h>

void firstFit(int block[], int m, int process[], int n)
{
    int allocation[20], i, j;

    for (i = 0; i < n; i++)
        allocation[i] = -1;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (block[j] >= process[i])
            {
                allocation[i] = j;
                block[j] -= process[i];
                break;
            }
        }
    }

    printf("\nFIRST FIT\n");
    printf("Process\tSize\tBlock\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t", i + 1, process[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

void bestFit(int block[], int m, int process[], int n)
{
    int allocation[20], i, j, best;

    for (i = 0; i < n; i++)
    {
        allocation[i] = -1;
        best = -1;

        for (j = 0; j < m; j++)
        {
            if (block[j] >= process[i])
            {
                if (best == -1 || block[j] < block[best])
                    best = j;
            }
        }

        if (best != -1)
        {
            allocation[i] = best;
            block[best] -= process[i];
        }
    }

    printf("\nBEST FIT\n");
    printf("Process\tSize\tBlock\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t", i + 1, process[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

void worstFit(int block[], int m, int process[], int n)
{
    int allocation[20], i, j, worst;

    for (i = 0; i < n; i++)
    {
        allocation[i] = -1;
        worst = -1;

        for (j = 0; j < m; j++)
        {
            if (block[j] >= process[i])
            {
                if (worst == -1 || block[j] > block[worst])
                    worst = j;
            }
        }

        if (worst != -1)
        {
            allocation[i] = worst;
            block[worst] -= process[i];
        }
    }

    printf("\nWORST FIT\n");
    printf("Process\tSize\tBlock\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t", i + 1, process[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

int main()
{
    int m, n, i;
    int block[20], process[20];
    int b1[20], b2[20], b3[20];

    printf("Enter number of memory blocks: ");
    scanf("%d", &m);

    printf("Enter block sizes:\n");
    for (i = 0; i < m; i++)
    {
        scanf("%d", &block[i]);
        b1[i] = b2[i] = b3[i] = block[i];
    }

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter process sizes:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &process[i]);

    firstFit(b1, m, process, n);
    bestFit(b2, m, process, n);
    worstFit(b3, m, process, n);

    return 0;
}