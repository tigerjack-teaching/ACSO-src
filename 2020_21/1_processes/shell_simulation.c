#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
  int i;
  pid_t pid1;
  int status;
  char comando[128], *argv[128], *pch;
  while (1) {
    printf("myshell# "); // il prompt dei comandi
    // il codice che segue separa gli argomenti e salva i puntatori in argv[]
    fgets(comando, 128, stdin);   // legge l'input dell'utente
    pch = strtok(comando, " \n"); // "parsa" il primo argomento
    for (i = 0; pch != NULL && i < 127; i++) {
      argv[i] = pch;
      pch = strtok(NULL, " \n"); // "parsa" gli argomenti successivi
    }
    if (i == 1) {
      // avoid passing null
      argv[1] = "";
      i++;
    }
    argv[i] = NULL; // termina l'array argv con NULL
    pid1 = fork();
    if (pid1 == 0) {
      execvp(argv[0], &argv[1]); // esegue la exec!
      perror("Errore esecuzione");
      exit(EXIT_FAILURE);
    }
    //else non necessaria data l'exec precedente
    pid1 = wait(&status);
    printf("figlio terminato con codice %d\n", status/256);
  } // il processo genitore (shell) torna a leggere un altro comando
}
