#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
  if (argc == 1){
    printf("%s\n","wgrep: searchterm [file ...]");
    exit(1);
  }
  char* term = argv[1];

  if (argc == 2){
    char string_buffer[4096];

    while(fgets(string_buffer, sizeof(string_buffer), stdin)!= NULL){
      if(strstr(string_buffer,term)){
        printf("%s",string_buffer);
      }
    }
  } else { 

    for (int i = 2; i < argc;i++){
      char* file = argv[i];
      FILE* fp = fopen(file,"r");
      if (fp == NULL){
        printf("%s\n","wgrep: cannot open file");
        exit(1);
      }

      char buffer[4096];

      while(fgets(buffer, sizeof(buffer), fp) != NULL){
        if (strstr(buffer,term)){
          printf("%s",buffer);
        }
      }
      fclose(fp);
    }
  }

  return 0;
}
