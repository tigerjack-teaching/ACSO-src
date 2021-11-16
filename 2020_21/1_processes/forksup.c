#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  pid_t pidget = getpid();
  printf("New binary running with pid %d\n", pidget);
  printf("n arguments is %d\n", argc);
  for (int i = 0; i < argc; i++) {
    printf("Argument %d is %s\n", i, argv[i]);
  }
  int x;
  scanf("%d", &x);

  return 0;
}
