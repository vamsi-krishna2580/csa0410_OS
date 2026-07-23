#include <stdio.h>
#include <pthread.h>

void *display(void *arg) {
    printf("Hello from Thread\n");
    return NULL;
}

int main() {
    pthread_t t;

    pthread_create(&t, NULL, display, NULL);
    pthread_join(t, NULL);

    printf("Main Thread\n");

    return 0;
}