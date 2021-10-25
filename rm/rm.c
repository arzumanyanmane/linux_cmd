//rm [OPTION]... FILE...
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

int isRegular(char* path) {
   struct stat S;
   stat(path, &S);
   return S_ISREG(S.st_mode);
}

int isDir(char* path) {
   struct stat S;
   stat(path, &S);
   return S_ISDIR(S.st_mode);
}

void removeFiles(char* path) {
    char newPath[1000];
    DIR* directory = opendir(path);
    if(directory != NULL){
        struct dirent* struct_;
        while((struct_ = readdir(directory)) != NULL) {
            if(strcmp(struct_->d_name , "..") == 0 || strcmp(struct_->d_name , ".") == 0 || strcmp(struct_->d_name , ".git") == 0) {
              continue;
            }
            strcpy(newPath, path);
            strcat(newPath, "/");
            strcat(newPath, struct_->d_name);
            if(isRegular(newPath)) {
              printf("removed file -> %s\n", newPath);
              remove(newPath);  
            }
            else if(isDir(newPath)) {
              printf("enter next dir -> [%s]\n", newPath);
              removeFiles(newPath);
              rmdir(newPath);
            }
        }
    }
    closedir(directory);
    rmdir(path);
}

int main(int argc, char **argv){
  if (argc < 3){
    printf("need to specify all arguments");
    return -1;
  }
  char *p;
  int run = 0;
  struct stat st;
  for(int i = 0; i < argc; ++i){
    if(strcmp( argv[i], "-f") == 0){
      run = 1;
    }
  }
  if(run == 0){
    printf("-f flag not specified");
    return -1;
  }
  if (isRegular(argv[1])){
    printf("removed file -> %s\n", argv[1]);
    remove(argv[1]);
  } else{
    removeFiles(argv[1]);
  }
  return 0;
}
