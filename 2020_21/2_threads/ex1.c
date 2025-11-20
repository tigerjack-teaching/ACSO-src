#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_mutex_t mutexA = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutexB = PTHREAD_MUTEX_INITIALIZER;

void foo(int val){
  pthread_mutex_lock(&mutexB);
  val *= 2;
  if (val > 4)
    pthread_mutex_unlock(&mutexB);
}

void* fun1(void* arg){
  pthread_mutex_lock(&mutexA);
  foo(* (int *) arg);
  pthread_mutex_unlock(&mutexA);
  if (* (int *) arg < 2)
    pthread_mutex_unlock(&mutexB);
  pthread_mutex_lock(&mutexA);
  printf("1");
  pthread_mutex_unlock(&mutexA);
}

void* fun2(void* arg){
  pthread_mutex_lock(&mutexA);
  pthread_mutex_lock(&mutexB);
  printf("1");
  pthread_mutex_unlock(&mutexB);
  pthread_mutex_unlock(&mutexA);
}

int main(int argc, char* argv[]){
  pthread_t th1, th2;
  int arg1 = 2;
  pthread_create(&th1, NULL, fun1, &arg1);
  pthread_create(&th2, NULL, fun2, NULL);
  pthread_join(th1, NULL);
  pthread_join(th2, NULL);
}
