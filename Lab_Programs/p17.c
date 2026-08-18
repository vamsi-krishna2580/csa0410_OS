#include <stdio.h>

int main()
{
    int n, m, i, j, count = 0;
    int allocation[10][10], maximum[10][10];
    int need[10][10], available[10];
    int finish[10] = {0};
    int safeSequence[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    printf("\nEnter Allocation Matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &allocation[i][j]);

    printf("\nEnter Maximum Matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &maximum[i][j]);

    printf("\nEnter Available Resources:\n");
    for (j = 0; j < m; j++)
        scanf("%d", &available[j]);

    /* Calculate Need Matrix */
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }

    printf("\nNeed Matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            printf("%d ", need[i][j]);
        printf("\n");
    }

    while (count < n)
    {
        int found = 0;

        for (i = 0; i < n; i++)
        {
            if (finish[i] == 0)
            {
                int possible = 1;

                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > available[j])
                    {
                        possible = 0;
                        break;
                    }
                }

                if (possible)
                {
                    for (j = 0; j < m; j++)
                        available[j] += allocation[i][j];

                    safeSequence[count] = i;
                    count++;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if (found == 0)
            break;
    }

    if (count == n)
    {
        printf("\nSystem is in SAFE STATE\n");
        printf("Safe Sequence: ");

        for (i = 0; i < n; i++)
        {
            printf("P%d", safeSequence[i]);

            if (i != n - 1)
                printf(" -> ");
        }
        printf("\n");
    }
    else
    {
        printf("\nSystem is in UNSAFE STATE\n");
    }

    return 0;
}