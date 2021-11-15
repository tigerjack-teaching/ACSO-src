/**
 * Template for threads usage
 */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int glob_counter = 0;

void *tf(void *tid);

int main(int argc, char *argv[]) {
  pthread_t t1, t2;
  /* 2nd: thread attributes (NULL for default). A thread can be joinable (return
  * an exit status) or detached.

  * 4th: argument of funcs. If more than one you have to create a struct. It
  * must be passed by reference as a pointer cast of type void.
  */
  int arg_fun1 = 1;
  pthread_create(&t1, NULL, tf, &arg_fun1);
  int arg_fun2 = 2;
  pthread_create(&t2, NULL, tf, &arg_fun2);

  void *ret_val;
  /*
   * 2nd: contains the copy of the argument of pthread_exit invoked by the child
   * thread
   */
  pthread_join(t1, &ret_val);
  printf("t1 ret_ret_val is %d\n", *(int *)ret_val);
  pthread_join(t2, &ret_val);
  printf("t2 ret_ret_val is %d\n", *(int *)ret_val);
  return 0;
}

void *tf(void *tid) {
  // local variables, change visibles only by 3ds
  printf("tf from %d\n", *(int *)tid);
  int counter = 0;
  counter++;
  // global var changes are visible by all threads. However, if no further
  // measure is taken, consistency is not ensured. Here the access is not
  // protected by anything (like a mutex or semaphore)
  glob_counter++;
  // static var, acts as a global var, but it has local visibility. Changes are
  // shared among threads.
  static int static_counter = 0;
  static_counter++;
  printf("Here's thread number %d, local counter is %d, global counter is %d, "
         "static counter is %d\n",
         *(int *)tid, counter, glob_counter, static_counter);

  int *ret_val = (int *)malloc(1 * sizeof(int));
  printf("Here\n");
  if (*(int *)tid == 1) {
    *ret_val = 1;
  } else {
    *ret_val = -1;
  }
  return (void *)ret_val;
}
