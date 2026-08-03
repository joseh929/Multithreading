#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_CATEGORIES 4
#define UPDATES_PER_CATEGORY 5

const char *categories[NUM_CATEGORIES] = {
    "Electronics", "Groceries", "Clothing", "Stationery"
};

int stock[NUM_CATEGORIES] = {50, 200, 80, 150}; 
int total_updates = 0;
pthread_mutex_t inventory_lock;

void *updateCategory(void *arg) {
    int id = *(int *) arg;

    for (int i = 0; i < UPDATES_PER_CATEGORY; i++) {
        sleep(1);   /* Simulate delay */

        pthread_mutex_lock(&inventory_lock);
        stock[id] += 10;   
        total_updates++;
        printf("[%s] Update #%d -> New stock level: %d units\n",
               categories[id], i + 1, stock[id]);
        pthread_mutex_unlock(&inventory_lock);
    }
    return NULL;
}

int main(void) {
    pthread_t threads[NUM_CATEGORIES];
    int ids[NUM_CATEGORIES];

    pthread_mutex_init(&inventory_lock, NULL);

    for (int i = 0; i < NUM_CATEGORIES; i++) {
        ids[i] = i;
        pthread_create(&threads[i], NULL, updateCategory, &ids[i]);
    }
    for (int i = 0; i < NUM_CATEGORIES; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&inventory_lock);

    printf("\nFINAL INVENTORY SUMMARY\n");
    for (int i = 0; i < NUM_CATEGORIES; i++) {
        printf("%-12s : %d units\n", categories[i], stock[i]);
    }
    printf("Total stock updates performed: %d\n", total_updates);
    printf("Inventory synchronization completed successfully.\n");
    return 0;
}