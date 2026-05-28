#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[]) {
  const char *filename = "numbers.txt";

  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return 0;
  }

  int sum = 0;
  char buffer[256];

  while (fgets(buffer, sizeof(buffer), fp) != NULL) {
    int is_int = 1;

    buffer[strcspn(buffer, "\n")] = '\0';

    if (buffer[0] == '\0') {
      is_int = 0;
    }

    for (int i = 0; buffer[i] != '\0'; ++i) {
      if (!isdigit((unsigned char)buffer[i])) {
        is_int = 0;
        break;
      }
    }

    if (is_int) {
      sum += atoi(buffer);
    } else {
      fprintf(stderr, "invalid input %s\n", buffer);
    }
  }

  printf("sum: %d\n", sum);
  fclose(fp);
  return 0;
}
