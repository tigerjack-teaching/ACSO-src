/* Count the Number of Files in a Directory */
#include <dirent.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <directory_path>\n", argv[0]);
    return 1;
  }

  DIR *dir = opendir(argv[1]);
  if (dir == NULL) {
    perror("opendir");
    return 1;
  }

  int fileCount = 0;
  struct dirent *entry;
  while ((entry = readdir(dir)) != NULL) {
    if (entry->d_type == DT_REG) { // Check if it's a regular file
      fileCount++;
    }
  }

  printf("Total files in %s: %d\n", argv[1], fileCount);

  closedir(dir);
  return 0;
}
