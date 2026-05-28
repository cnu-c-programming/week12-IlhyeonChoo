#include <stdio.h>

int main(int argc, const char *argv[]) {
  if (argc < 2)
    return 0;

  FILE *fp = fopen(argv[1], "r");

  int count[26] = {0};
  int ch;

  while ((ch = fgetc(fp)) != EOF) {
    if ('a' <= ch && ch <= 'z') {
      count[ch - 'a']++;
    }
  }

  fclose(fp);

  for (int i = 0; i < 26; i++) {
    printf("%c: %d\n", 'a' + i, count[i]);
  }

  return 0;
}
