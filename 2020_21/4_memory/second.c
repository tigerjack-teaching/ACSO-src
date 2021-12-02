/*
 * Print some addresses that falls into the different VMA segments shown during
 * the lectures.
 * Compile the program using gcc -o programName sourceCode.c -lpthread
 * Run the program as setarch `uname -m` -R ./programName
 * to temporarily disable ASLR.
 *
 * While the program is running, call cat /proc/NN/maps from another shell to
 * see the mappings inside the OS
 */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

// global variables, one initialized, the other not
int our_init_data = 30;
int our_noinit_data;

void *donothing(void* arg) {
  int thread_local = 1;
  printf("\n ?) Thread          segment (T) = %p\n", &thread_local);
  while (1)
    ;
}

void our_prints(void) {
  int our_local_data = 1;
  int* ptr = (int*) malloc(sizeof(int));
  pthread_t t1;
  pthread_create(&t1, NULL, donothing, NULL);
  printf("\nPid of the process is = %d", getpid());
  printf("\nAddresses which fall into:");
  printf("\n 1) Code            segment (C) = %p", &our_prints);
  printf("\n 2) Data            segment (S) = %p", &our_init_data);
  printf("\n 3) BSS             segment (inside D) = %p", &our_noinit_data);
  printf("\n 5) Heap            segment (D) = %p", ptr);
  printf("\n 6) Memory mapping  segment (M) = %p", &printf);
  printf("\n 7) Stack           segment (P) = %p\n", &our_local_data);

  printf("At this point, you can execute, on another shell\n");
  printf("cat /proc/%d/maps\n", getpid());
  pthread_join(t1, NULL);

  while (1) ;
}

int main() {
  our_prints();
  return 0;
}
