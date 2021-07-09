/******************************************************
 * @author Ricardo Barbosa
 * @version 04.07.2020
 * Title: Lab 5 - Step 2
 * Description: Corrects the issue from step1 where
 * the number of repeated outputs is eliminated
 * ***************************************************/

#include <stdlib.h>
#include <pthread.h>
void *go(void *);
#define NTHREADS 10
pthread_t threads[NTHREADS];

typedef struct thread_t {
   int data;
} thread_t;

thread_t* ptr[NTHREADS];

int main() {
   int i;
   for (i = 0; i < NTHREADS; i++){
      ptr[i] = malloc(sizeof(thread_t));
      ptr[i]->data = i; 
      pthread_create(&threads[i], NULL, go, ptr[i]);
   }
   for (i = 0; i < NTHREADS; i++) {
      printf("Thread %d returned\n", i);
      pthread_join(threads[i],NULL);
   }
   printf("Main thread done.\n");
   return 0;
}
void *go(void *arg) {

printf("Hello from thread %d with iteration %d\n", (int)pthread_self(), *(int *)arg);

return 0;
}
