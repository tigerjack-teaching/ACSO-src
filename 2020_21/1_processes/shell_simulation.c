#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
  int i;
  pid_t pid1;
  int status;
  char command[128], *argv[128], *pch;
  while (1) {
    printf("myshell# "); // command prompt
    // splits the arguments and saves the pointers in argv[]
    fgets(command, 128, stdin);   // read user input
    pch = strtok(command, " \n"); // parse first argument
    for (i = 0; pch != NULL && i < 127; i++) {
      argv[i] = pch;
      pch = strtok(NULL, " \n"); // arguments parsing
    }
    argv[i] = NULL; // termina l'array argv con NULL
    pid1 = fork();
    if (pid1 == -1) {
      perror("Fork failed");
      exit(1);
    }
    if (pid1 == 0) {
      execvp(argv[0], &argv[0]); 
      perror("Command execution failed");
      exit(EXIT_FAILURE);
    }
    // This code is executed by the parent process
    // else non necessary bcz of exec or exit
    pid1 = wait(&status);
    /* printf("figlio terminato con codice %d\n", status/256); */
    printf("child terminated with code %d\n", WEXITSTATUS(status));
  } // il processo genitore (shell) torna a leggere un altro command
}
