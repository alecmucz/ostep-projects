#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

  if(argc == 1){
    printf("%s\n","wzip: file1 [file2 ...]");
    exit(1);
  }

  int prev_char = -1;
  int count = 0;

  for(int i = 1; i < argc; i++){
    char* f  = argv[i];
    FILE* fp = fopen(f,"r");
    if (fp == NULL){
      printf("%s\n","wzip: cannot open file");
      exit(1);
    }

    int curr_char;
    while((curr_char = fgetc(fp)) != EOF){
      if (prev_char == -1){
        prev_char = curr_char;
        count++;
      } else if (curr_char == prev_char) {
        count++;
      } else {
        fwrite(&count,sizeof(int),1,stdout);
        fwrite(&prev_char,sizeof(char),1,stdout);
        prev_char = curr_char;
        count = 1;
      }
    }
    fclose(fp);
  }

  if (prev_char != -1){
    fwrite(&count,sizeof(int),1,stdout);
    fwrite(&prev_char,sizeof(char),1,stdout);
  }
  return 0;
}
