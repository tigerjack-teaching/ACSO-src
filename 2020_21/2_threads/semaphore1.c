#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

sem_t sem1;

void *tf1(void *arg) {
  int val;
  // wait until the value of sem1 > 0; after wait, sem1.value--
  sem_wait(&sem1);
  // when we are here, we may not be the only one; sems are not necessarily binary
  sem_getvalue(&sem1, &val);
  printf("from tf1, pid %lu, sem is %d\n", pthread_self(), val);
  // sem1.value++; notify all
  sem_post(&sem1);
  return 0;
}

int main(int argc, char *argv[]) {
  pthread_t td1, td2, td3, td4;
  // semaphore; 0 for sharing b/w threads, non-zero b/w processes; init value
  sem_init(&sem1, 0, 2);
  pthread_create(&td1, NULL, &tf1, NULL);
  pthread_create(&td2, NULL, &tf1, NULL);
  pthread_create(&td3, NULL, &tf1, NULL);
  pthread_create(&td4, NULL, &tf1, NULL);
  pthread_join(td1, NULL);
  pthread_join(td2, NULL);
  pthread_join(td3, NULL);
  pthread_join(td4, NULL);
  sem_destroy(&sem1);
  return 0;
}
