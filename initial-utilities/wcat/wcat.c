#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  for (int i = 1; i < argc; i++){
    char* file = argv[i];
    FILE *fp = fopen(file, "r");

    if (fp == NULL){
      printf("%s\n", "wcat: cannot open file");
      exit(1);
    }
   
    char buffer[4096];
    while (fgets(buffer, sizeof(buffer),fp) != NULL){
      printf("%s",buffer);
    }
    
    fclose(fp);
  }

  return 0;
}
