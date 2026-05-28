#include <stdio.h>
#include <string.h>

typedef struct student {
  char name[64];
  int score;
} Student;

int main(int argc, const char *argv[]) {
  FILE *fp = fopen("student.txt", "r");
  int count = 0;
  Student students[64];

  while (1) {
    Student tmp;
    fscanf(fp, "%63s %d", tmp.name, &tmp.score);
    if (feof(fp)) {
      break;
    }
    students[count] = tmp;
    count++;
    // printf("%s %d\n", tmp.name, tmp.score);
    // printf("%d\n", count);
  }

  int max = 0;
  float avg = 0;
  int score_sum = 0;

  for (int i = 0; i < count; ++i) {
    int current_score = students[i].score;
    score_sum += current_score;
    if (max < current_score) {
      max = current_score;
    }
  }

  avg = score_sum / count;

  // printf("sum: %d\n", score_sum);
  printf("max: %d\n", max);
  printf("avg: %.2f\n", avg);

  fclose(fp);

  return 0;
}
