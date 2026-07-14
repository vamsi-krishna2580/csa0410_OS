#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t chopstick[5];

void *philosopher(void *num) {
    int i = *(int *)num;

    pthread_mutex_lock(&chopstick[i]);
    pthread_mutex_lock(&chopstick[(i + 1) % 5]);

    printf("Philosopher %d is Eating\n", i);

    sleep(1);

    pthread_mutex_unlock(&chopstick[i]);
    pthread_mutex_unlock(&chopstick[(i + 1) % 5]);

    return NULL;
}

int main() {
    pthread_t tid[5];
    int id[5];

    for (int i = 0; i < 5; i++)
        pthread_mutex_init(&chopstick[i], NULL);

    for (int i = 0; i < 5; i++) {
        id[i] = i;
        pthread_create(&tid[i], NULL, philosopher, &id[i]);
    }

    for (int i = 0; i < 5; i++)
        pthread_join(tid[i], NULL);

    return 0;
}