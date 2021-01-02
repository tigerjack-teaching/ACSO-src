#include <stdio.h>
/* #include "long_code.c" //questa funzione occupa circa 3 pagine di codice */
#define PAGE_SIZE 4096
long unsigned pointer;
int main() {
  pointer = &main;
  printf("NPV of main %12.12lx \n", pointer/ PAGE_SIZE);
  pointer = &printf;
  printf("NPV of printf %12.12lx \n", pointer/ PAGE_SIZE);
  //long_code(); commentato nella prima prova
  /* VIRTUAL_AREAS; */
  return 0;
}
