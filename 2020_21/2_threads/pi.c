#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

/*Number of points*/
unsigned int num_points = 0;

/*Number of threads*/
unsigned int num_threads = 0;

/*Points inside the circle*/
unsigned int inside_points = 0;

/*Mutex */
// Only 1 thread at a time can update the global result
pthread_mutex_t mutex;

/**
 * Check if some random points are inside or outside a loop with radius 1
 * @param data is the index identifying the thread
 */
void *check_points(void *data) {
  /* The index of the current thread */
  unsigned int index = *((unsigned int *)data);
  unsigned int seed = index;

  /* The number of points to be examined by this thread */
  unsigned int num_points_per_thread =
      num_points / num_threads + (index < num_points % num_threads ? 1 : 0);
  unsigned int i;
  unsigned int local_count = 0;
  /* The core of the application */
  for (i = 0; i < num_points_per_thread; i++) {
    double x = (double)rand_r(&seed) / (double)RAND_MAX;
    double y = (double)rand_r(&seed) / (double)RAND_MAX;
    printf("Thread %d - Point %f %f\n", index, x, y);
    if (x * x + y * y <= 1)
      local_count++;
  }
  printf("Thread %d - Inside points %d/%d\n", index, local_count,
         num_points_per_thread);
  fflush(stdout);

  /* Lock and update global result */
  pthread_mutex_lock(&mutex);
  inside_points += local_count;
  pthread_mutex_unlock(&mutex);
  return 0;
}

int main(int argc, char **argv) {
  if (argc != 3) {
    printf("Wrong number of parameters\n");
    return 0;
  }
  /* The number of points */
  num_points = (unsigned int)atoi(argv[1]);
  printf("Number of points is %d\n", num_points);

  /* The number of threads */
  num_threads = (unsigned int)atoi(argv[2]);

  /* Thread data structure */
  pthread_t threads[num_threads];
  unsigned int indexes[num_threads];

  /*Initialize the mutex*/
  pthread_mutex_init(&mutex, NULL);

  /* Create the threads */
  unsigned int index;
  for (index = 0; index < num_threads; index++) {
    indexes[index] = index;
    pthread_create(&threads[index], NULL, check_points,
                   (void *)&indexes[index]);
  }
  for (index = 0; index < num_threads; index++) {
    pthread_join(threads[index], NULL);
  }

  /* Compute the final result */
  double pi = (4.0 * inside_points) / num_points;
  fprintf(stdout, "Computed pi is %f\n", pi);

  /* Deallocate structures */
  pthread_mutex_destroy(&mutex);
  return 0;
}
