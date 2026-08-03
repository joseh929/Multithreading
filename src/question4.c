#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_DEPARTMENTS 4

const char *department_names[NUM_DEPARTMENTS] = {
    "Computer Science", "Mathematics", "Physics", "Business Studies"
};

int departments_done = 0;
pthread_mutex_t lock;
pthread_cond_t all_done_cond;

void *processDepartment(void *arg) {
    int id = *(int *) arg;

    printf("[%s] Processing marks...\n", department_names[id]);
    sleep(1 + id);   /* Simulating processing time */
    printf("[%s] Marks processing complete.\n", department_names[id]);

    pthread_mutex_lock(&lock);
    departments_done++;
    if (departments_done == NUM_DEPARTMENTS) {
        pthread_cond_signal(&all_done_cond);   /* Signal reporting thread */
    }
    pthread_mutex_unlock(&lock);

    return NULL;
}

void *reportingThread(void *arg) {
    pthread_mutex_lock(&lock);
    while (departments_done < NUM_DEPARTMENTS) {
        pthread_cond_wait(&all_done_cond, &lock);   /* Sleep until signaled */
    }
    pthread_mutex_unlock(&lock);

    printf("\n=== FINAL CLASS REPORT ===\n");
    printf("All %d departments have submitted their marks.\n", NUM_DEPARTMENTS);
    printf("Final report generated successfully.\n");
    return NULL;
}

int main(void) {
    pthread_t dept_threads[NUM_DEPARTMENTS], report_thread;
    int ids[NUM_DEPARTMENTS];

    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&all_done_cond, NULL);

    pthread_create(&report_thread, NULL, reportingThread, NULL);

    for (int i = 0; i < NUM_DEPARTMENTS; i++) {
        ids[i] = i;
        pthread_create(&dept_threads[i], NULL, processDepartment, &ids[i]);
    }

    for (int i = 0; i < NUM_DEPARTMENTS; i++) {
        pthread_join(dept_threads[i], NULL);
    }
    pthread_join(report_thread, NULL);

    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&all_done_cond);
    return 0;
}