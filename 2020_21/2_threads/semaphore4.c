#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

sem_t sem1, sem2;
/*
 * In response to: "What happens when a semaphore is not initialized?"
 */
int main(int argc, char *argv[])
{
  int val1, val2;
  sem_init(&sem2, 0, 2);
  sem_getvalue(&sem1, &val1);
  sem_getvalue(&sem2, &val2);
  // sem1: val1 is 0, but sem1 is null
  // sem2: val2 is 2, but sem2 is initialized (though not printable)
  printf("%d %d\n", val1, val2);
  printf("%s %s\n", sem1, sem2);
  // val1 increased, sem1 still null
  sem_post(&sem1);
  sem_getvalue(&sem1, &val1);
  printf("%d\n", val1);
  printf("%s\n", sem1);
  sem_wait(&sem1);
  printf("%d\n", val1);
  printf("%s\n", sem1);
  return 0;
}
