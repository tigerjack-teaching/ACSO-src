#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

sem_t sem1, sem2;

void *print1(void *args) {
  printf("a");
  sem_post(&sem1);
  sem_wait(&sem2);
  printf("b");
  sem_post(&sem1);
  sem_wait(&sem2);
  printf("c");
  sem_post(&sem1);

  return (void *)1;
}

void *print2(void *args) {
  sem_wait(&sem1);
  printf("1");
  sem_post(&sem2);
  sem_wait(&sem1);
  printf("2");
  sem_post(&sem2);
  sem_wait(&sem1);
  printf("3");

  return (void *)2;
}

int main(int argc, char *argv[]) {
  pthread_t td1, td2;
  sem_init(&sem1, 0, 0);
  sem_init(&sem2, 0, 0);
  pthread_create(&td1, NULL, &print1, NULL);
  pthread_create(&td2, NULL, &print2, NULL);
  int rval1, rval2;
  pthread_join(td1, (void *)&rval1);
  pthread_join(td2, (void *)&rval2);
  printf("\nrval1 %d rval2 %d\n", rval1, rval2);
  return 0;
}
