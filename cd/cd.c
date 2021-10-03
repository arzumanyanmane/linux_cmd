// cd [option] [directory]
// zsh: bus error ?
#include <stdio.h>
#include <unistd.h> 
#include <dirent.h>
#include <errno.h>
int main(int argc, char **argv){   
  if(argc == 1){
    chdir("/");
  }else if (argc == 2){
    printf("Trying to redirect to %s\n", argv[1]);
    DIR* dir = opendir(argv[1]);
    if (dir) {
      printf("Directory exists.\n");
      closedir(dir);
      chdir(argv[1]);
    } else if (ENOENT == errno) {
      printf("Directory does not exist. \n");
    } else {
      printf("opendir() failed for some other reason.\n"); 
    }
  }  
  printf("last directory : %s\n", getcwd("", 100));
  return 0;
}