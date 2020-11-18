#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  // check htop/top after this
  // Funziona solo sotto WSL/WSL2
  /* execlp("notepad.exe", NULL); */
  /* execlp("/bin/ls", "ls", "-l", "--color=always", NULL); */
  execl("./1sup.out", "1sup.out", "do", "i", "wanna", "know", NULL);
  printf("Exec error");
  return 0;
}
