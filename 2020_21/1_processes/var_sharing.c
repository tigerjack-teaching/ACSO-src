#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int globalV; /*  A global variable*/
int main(void) {
  int stackV = 0;
  int *heapV = (int *)malloc(2 * sizeof(int));
  pid_t childPID = fork();
  *heapV = 0;
  if (childPID == 0) { // child process
    printf("\n[Child] :: stackV = %d, globalV = %d", stackV, globalV);
    stackV++;
    globalV++;
    printf("\n[Child] :: stackV = %d, globalV = %d", stackV, globalV);
    printf("\n[Child] :: heapV :: address = %p, value = %d", heapV, *heapV);
    *heapV = 50;
    printf("\n[Child] :: heapV :: address = %p, value = %d", heapV, *heapV);
    *heapV = 200;
    printf("\n[Child] :: heapV :: address = %p, value = %d", heapV, *heapV);
    int *heapV2 = (int *)malloc(2 * sizeof(int));
    printf("\n[Child] :: heapV2 :: address = %p", heapV2);
  } else { // Parent process
    printf("\n[Parent] :: stackV = %d, globalV = %d", stackV, globalV);
    stackV = 10;
    globalV = 20;
    printf("\n[Parent] :: stackV = %d, globalV = %d", stackV, globalV);
    printf("\n[Parent] :: heapV :: address = %p, value = %d", heapV, *heapV);
    *heapV = 100;
    printf("\n[Parent] :: heapV :: address = %p, value = %d", heapV, *heapV);
    *heapV = 400;
    printf("\n[Parent] :: heapV :: address = %p, value = %d", heapV, *heapV);
    int *heapV2 = (int *)malloc(3 * sizeof(int));
    *heapV2 = 3;
    printf("\n[Parent] :: heapV2 :: address = %p", heapV2);
  }
  return 0;
}
