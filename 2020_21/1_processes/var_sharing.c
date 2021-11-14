#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int globalVar; /*  A global variable*/

int main(void) {
  int localVar = 0;
  int *p = (int *)malloc(1 * sizeof(int));
  pid_t childPID = fork();

  // Putting value at allocated address
  *p = 0;

  if (childPID == 0) // child process
  {
    printf("\n [Child] Initial Value :: localVar"
           " = %d, globalVar = %d",
           localVar, globalVar);
    localVar++;
    globalVar++;

    int c = 500;
    printf("\n [Child] :: localVar address = %p,"
           " value = %d",
           &localVar, localVar);
    printf("\n [Child] :: globalVar address = %p,"
           " value = %d",
           &globalVar, globalVar);
    printf("\n [Child] Address of malloced mem child = %p "
           "and value is %d",
           p, *p);
    *p = 50;
    printf("\n [Child] Address of malloced mem child = %p "
           "and value is %d",
           p, *p);
    *p = 200;
    printf("\n [Child] Address of malloced mem child = %p "
           "and value is %d\n\n\n",
           p, *p);
  } else // [Parent]
  {
    printf("\n [Parent] Initial Value :: "
           "localVar = %d, globalVar = %d",
           localVar, globalVar);

    localVar = 10;
    globalVar = 20;
    printf("\n [Parent] :: localVar address = %p,"
           " value = %d",
           &localVar, localVar);
    printf("\n [Parent] :: globalVar address = %p,"
           " value = %d", &globalVar, globalVar);
    printf("\n [Parent] Address of malloced mem parent= %p "
           "and value is %d",
           p, *p);
    *p = 100;
    printf("\n [Parent] Address of malloced mem parent= %p "
           "and value is %d",
           p, *p);
    *p = 400;
    printf("\n [Parent] Address of malloced mem child = %p"
           " and value is %d \n",
           p, *p);
  }
  return 0;
}
