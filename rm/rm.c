//rm [OPTION]... FILE...
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>

int isRegular(char* path) {
   struct stat S;
   stat(path, &S);
   return S_ISREG(S.st_mode);
}

int main(int argc, char **argv){
  if (argc < 2){
    return -1;
  }
  char *p;
  struct stat st;

  if (isRegular(argv[1])){
    remove(argv[1]);
  }else{
    printf("provide only files please\n");
  }
  return 0;
}
