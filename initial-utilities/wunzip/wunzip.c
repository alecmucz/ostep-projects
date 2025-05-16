#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
  if (argc == 1){
    printf("%s\n","wunzip: file1 [file2 ...]");
    exit(1);
  }

  for (int i = 1; i < argc; i++){
    char* file = argv[i];
    FILE* fp   = fopen(file,"r");

    int count;
    char c;
    while (fread(&count, sizeof(int), 1, fp) == 1 &&
           fread(&c   , sizeof(char), 1 ,fp) == 1){
      for(int j = 0; j < count;j++){
        putchar(c);
      }
    }
  }

  return 0;
}
