#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct config {
  char InputFileName[64];
  int Options;
  char SectionName[64];
  unsigned long long Address;
} Config;

void config_parser(Config *config_ptr) {
  FILE *fp = fopen("config.txt", "r");

  fscanf(fp, "InputFileName=%63s\n", config_ptr->InputFileName);
  fscanf(fp, "Options=%d\n", &config_ptr->Options);
  fscanf(fp, "SectionName=%63s\n", config_ptr->SectionName);
  fscanf(fp, "Address=%llx\n", &config_ptr->Address);

  fclose(fp);
}

int main(int argc, const char *argv[]) {
  Config config;
  config_parser(&config);

  printf("config: %s %d %s %llu\n", config.InputFileName, config.Options,
         config.SectionName, config.Address);
  return 0;
}
