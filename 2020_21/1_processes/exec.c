#include <stdio.h>

int main(int argc, char *argv[]) {
  // Check if there are any command-line arguments
  for (int i = 0; i < argc; i++) {
    printf("Argument %d: %s\n", i, argv[i]);
  }

  return 0;
}
