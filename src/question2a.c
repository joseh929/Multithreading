#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
#define DEPOSITS_PER_THREAD 10000
#define DEPOSIT_AMOUNT 1000

long balance = 0;   /* Shared resource */

void *deposit(void *arg) {
    for (int i = 0; i < DEPOSITS_PER_THREAD; i++) {
        balance += DEPOSIT_AMOUNT;   /* Race condition here */
    }
    return NULL;
}

int main(void) {
    pthread_t threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, deposit, NULL);
    }
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Final balance (no synchronization): KES %ld\n", balance);
    printf("Expected balance: KES %d\n",
           NUM_THREADS * DEPOSITS_PER_THREAD * DEPOSIT_AMOUNT);
    return 0;
}