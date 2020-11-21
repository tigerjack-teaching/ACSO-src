#include <pthread.h>
#include <stdio.h>
/* for sleep */
#include <unistd.h>

void * fun(void * arg) {
  sleep(1);
  printf("exiting fun\n");
}

int main(int argc, char *argv[])
{
  pthread_t td1, td2;
  pthread_create(&td1, NULL, fun, NULL);
  pthread_create(&td2, NULL, fun, NULL);
  //no join, main exit, child dies
  printf("exiting main\n");
  return 0;
}

