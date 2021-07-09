/*****************************************************
 * @author Ricardo Barbosa
 * @version 04.07.2020
 * Title: Lab 5 - Step 3
 * Description: Multiplies two matrices and 
 * produces the product in matrixC
 * **************************************************/


#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>
void *go(void *);

//variables globally defined
#define NTHREADS 10
#define N 1024
#define M 1024
#define L 1024

//array of threads
pthread_t threads[N];

//matrices declared
double matrixA[N][M];
double matrixB[M][L];
double matrixC[N][L];

//struct defined 
typedef struct thread_t {
   int data;
} thread_t;

thread_t* ptr[NTHREADS];

//main function
int main() {
   int i = 0;
   int j = 0;

   //number generator provided by PDF
   //matrix A defined 
   srand(time(NULL));
      for (i = 0; i < N; i++){
         for (j = 0; j < M; j++){
            matrixA[i][j] = rand();
         }
      }
   //number generator provided by PDF
   //matrix B defined 
   srand(time(NULL));
      for (i = 0; i < M; i++){
         for (j = 0; j < L; j++){
            matrixB[i][j] = rand();
         }
      }

   //allocating memory to the heap with each element of the pointer array
   for (i = 0; i < N; i++){
   ptr[i] = malloc(sizeof(thread_t));
   ptr[i]->data = i; 
   pthread_create(&threads[i], NULL, go, ptr[i]);
   }
   //pthread_join used as a wait function
   for (i = 0; i < N; i++) {
      printf("Thread %d returned\n", i);
      pthread_join(threads[i], NULL);
   }
   //matrix C defined after threads terminate
   printf("Main thread done.\n");
   for (i=0; i < N; i++){
      printf("row %d\n", i);
      for(j=0; j < L; j++){
         printf("Matrix C %.2f\n", matrixC[i][j]);
      }
   }
   return 0;
}

//go() function defined
void *go(void *arg) {
   int j = 0;
   int k = 0;
   int z = *(int *)arg;

   for (j = 0; j < L; j++){
      double temp = 0;
         for (k = 0; k < M; k++){
            temp += matrixA[z][k] * matrixB[k][j];
         }
      matrixC[z][j] = temp;
   }
   return 0;
}
