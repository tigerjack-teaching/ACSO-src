/* List Files with a Specific Extension */

#include <dirent.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <directory_path> <file_extension>\n", argv[0]);
    return 1;
  }

  DIR *dir = opendir(argv[1]);
  if (dir == NULL) {
    perror("opendir");
    return 1;
  }

  char *fileExtension = argv[2];
  int extensionLength = strlen(fileExtension);

  struct dirent *entry;
  while ((entry = readdir(dir)) != NULL) {
    if (entry->d_type == DT_REG) { // Check if it's a regular file
      int nameLength = strlen(entry->d_name);
      if (nameLength > extensionLength &&
          strcmp(entry->d_name + nameLength - extensionLength, fileExtension) ==
              0) {
        printf("%s\n", entry->d_name);
      }
    }
  }

  closedir(dir);
  return 0;
}
