#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>


char buffer;
sem_t empty, full;

void * readd(void * args) {
  int * reps = (int *) args;
  for(int i = 0; i < *reps; i++) {
    printf("R: i %d\n", i);
    sem_wait(&full);
    printf("buffer %c\n", buffer);
    sem_post(&empty);
  }
  return NULL;
}

void * writee(void * args) {
  int * reps = (int *) args;
  for(int i = 0; i < *reps; i++) {
    printf("W: i %d\n", i);
    sem_wait(&empty);
    buffer = 'a' + (i % 26);
    sem_post(&full);
  }
  return NULL;
}

int main(int argc, char *argv[])
{
  sem_init(&empty, 0, 1);
  sem_init(&full, 0, 0);
  pthread_t td1, td2;
  int tot = 10;
  pthread_create(&td1, NULL, &readd,  &tot);
  pthread_create(&td2, NULL, &writee, &tot);
  pthread_join(td1, NULL);
  pthread_join(td2, NULL);

  return 0;
}
