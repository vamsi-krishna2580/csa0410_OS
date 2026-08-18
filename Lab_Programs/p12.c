#include <stdio.h>

#define N 5

int forks[N] = {1, 1, 1, 1, 1};

void philosopher(int i)
{
    int left = i;
    int right = (i + 1) % N;

    printf("\nPhilosopher %d is thinking", i + 1);

    if (forks[left] && forks[right])
    {
        forks[left] = 0;
        forks[right] = 0;

        printf("\nPhilosopher %d takes forks %d and %d",
               i + 1, left + 1, right + 1);
        printf("\nPhilosopher %d is eating", i + 1);

        forks[left] = 1;
        forks[right] = 1;

        printf("\nPhilosopher %d releases forks %d and %d\n",
               i + 1, left + 1, right + 1);
    }
    else
    {
        printf("\nPhilosopher %d is waiting for forks\n", i + 1);
    }
}

int main()
{
    int i, choice;

    while (1)
    {
        printf("\n--- DINING PHILOSOPHERS ---");
        printf("\n1. Philosopher wants to eat");
        printf("\n2. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 2)
            break;

        printf("Enter philosopher number (1-5): ");
        scanf("%d", &i);

        if (i >= 1 && i <= 5)
            philosopher(i - 1);
        else
            printf("Invalid philosopher number\n");
    }

    return 0;
}