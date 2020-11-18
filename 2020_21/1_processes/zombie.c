#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  while (1) {
    printf("Press Enter to execute ls");
    while (getchar() != '\n')
      ;
    if (!fork()) {
      sleep(10);
      /* printf("child\n"); */
      execl("/bin/ls", "ls", NULL);
    } /* else { */
    /*   printf("father\n"); */
    /* } */
  }
  return 0;
}
