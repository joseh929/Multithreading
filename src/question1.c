#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

typedef struct {
    int task_number;
} TaskArg;

/* Worker thread function */
void *worker(void *arg) {
    TaskArg *task = (TaskArg *) arg;

    printf("Thread ID: %lu | Task %d has started execution.\n",
           (unsigned long) pthread_self(), task->task_number);

    return NULL;
}

int main(void) {
    pthread_t threads[NUM_THREADS];
    TaskArg tasks[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        tasks[i].task_number = i + 1;      /* Assign unique task number */
        if (pthread_create(&threads[i], NULL, worker, &tasks[i]) != 0) {
            perror("pthread_create failed");
            exit(EXIT_FAILURE);
        }
    }

    /* Main thread waits for every worker to complete */
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All scheduled tasks have completed successfully.\n");
    return 0;
}