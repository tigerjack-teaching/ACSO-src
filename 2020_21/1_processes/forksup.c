#include <stdio.h>

int main(int argc, char *argv[]) {
  printf("program running\n");
  printf("n arguments is %d\n", argc);
  for (int i = 0; i < argc; i++) {
    printf("Argument %d is %s\n", i, argv[i]);
  }
  int x;
  scanf("%d", &x);

  return 0;
}
