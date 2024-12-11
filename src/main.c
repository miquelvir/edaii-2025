#include "sample_lib.h"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

void createaleak() { char *foo = malloc(20 * sizeof(char)); }

int main() {
  printf("*****************\nWelcome to EDA 2!\n*****************\n");

  // how to import and call a function
  printf("Factorial of 4 is %d\n", fact(4));

  // how to find all files in a folder
  char *path = "./datasets/wikipedia12";
  printf("The files in %s are:\n", path);
  struct dirent *entry;
  struct stat statbuf;
  DIR *dp = opendir(path);

  if (dp == NULL) {
    perror("opendir");
    return 1;
  }

  while ((entry = readdir(dp)) != NULL) {
    char relativePath[1024];
    snprintf(relativePath, sizeof(relativePath), "%s/%s", path, entry->d_name);

    if (stat(relativePath, &statbuf) == -1 || !S_ISREG(statbuf.st_mode)) {
      continue;
    }

    printf("  %s in %s\n", entry->d_name, relativePath);
  }

  closedir(dp);

  // uncomment and run "make v" to see how valgrind detects memory leaks
  // createaleak();

  return 0;
}