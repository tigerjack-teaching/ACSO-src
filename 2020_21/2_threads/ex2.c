#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

pthread_mutex_t mutexA = PTHREAD_MUTEX_INITIALIZER;
int c = 0, e = 0;

void* fun1(void* arg){
  int a = 0, b = * (int *)arg;
  pthread_mutex_lock(&mutexA);
  e = 1;
  a = b + c;
  pthread_mutex_unlock(&mutexA);
  return (void *) (intptr_t)a;
}

void* fun2(void* arg){
  while (e == 0){}
  pthread_mutex_lock(&mutexA);
  c = (* (int *) arg) * 2;
  pthread_mutex_unlock(&mutexA);
  return (void *) &c;
}

int main(int argc, char* argv[]){
  pthread_t th1, th2;
  int d, x = 3, y = 4;
  pthread_create(&th1, NULL, fun1, &x);
  pthread_create(&th2, NULL, fun2, &y);
  pthread_join(th1, (void *) &d);
  pthread_join(th2, (void *) &d);
  return EXIT_SUCCESS;
}
