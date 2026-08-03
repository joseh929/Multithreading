#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5
#define ITEMS_TO_PRODUCE 10

int buffer[BUFFER_SIZE];
int in = 0, out = 0;
int count = 0;

sem_t empty_slots;   
sem_t full_slots;    
pthread_mutex_t buffer_lock;

void *producer(void *arg) {
    for (int i = 1; i <= ITEMS_TO_PRODUCE; i++) {
        sem_wait(&empty_slots);        
        pthread_mutex_lock(&buffer_lock);

        buffer[in] = i;
        in = (in + 1) % BUFFER_SIZE;
        count++;
        printf("[Producer] produced product #%d | buffer count: %d/%d\n",
               i, count, BUFFER_SIZE);

        pthread_mutex_unlock(&buffer_lock);
        sem_post(&full_slots);         
        usleep(100000);
    }
    return NULL;
}

void *consumer(void *arg) {
    for (int i = 1; i <= ITEMS_TO_PRODUCE; i++) {
        sem_wait(&full_slots);         
        pthread_mutex_lock(&buffer_lock);

        int product = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        count--;
        printf("[Consumer] consumed product #%d | buffer count: %d/%d\n",
               product, count, BUFFER_SIZE);

        pthread_mutex_unlock(&buffer_lock);
        sem_post(&empty_slots);        
        usleep(150000);
    }
    return NULL;
}

int main(void) {
    pthread_t prod, cons;

    sem_init(&empty_slots, 0, BUFFER_SIZE);
    sem_init(&full_slots, 0, 0);
    pthread_mutex_init(&buffer_lock, NULL);

    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    sem_destroy(&empty_slots);
    sem_destroy(&full_slots);
    pthread_mutex_destroy(&buffer_lock);

    printf("All products have been produced and consumed.\n");
    return 0;
}