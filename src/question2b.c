#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
#define DEPOSITS_PER_THREAD 10000
#define DEPOSIT_AMOUNT 1000

long balance = 0;
pthread_mutex_t balance_lock;

void *deposit(void *arg) {
    for (int i = 0; i < DEPOSITS_PER_THREAD; i++) {
        pthread_mutex_lock(&balance_lock);
        balance += DEPOSIT_AMOUNT;      /* Protected critical section */
        pthread_mutex_unlock(&balance_lock);
    }
    return NULL;
}

int main(void) {
    pthread_t threads[NUM_THREADS];
    pthread_mutex_init(&balance_lock, NULL);

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, deposit, NULL);
    }
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&balance_lock);
    printf("Final balance (with mutex): KES %ld\n", balance);
    printf("Expected balance: KES %d\n",
           NUM_THREADS * DEPOSITS_PER_THREAD * DEPOSIT_AMOUNT);
    return 0;
}