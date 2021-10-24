// cd [option] [directory]
#include <stdio.h>
#include <unistd.h> 
#include <dirent.h>
#include <errno.h>
#include <limits.h>


int main(int argc, char **argv){ 
  char cwd[PATH_MAX];  
  printf("%i", PATH_MAX);
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
      printf("opendir() failed for some other reason. %d\n", errno); 
    }
  }  
  if (getcwd(cwd, sizeof(cwd)) != NULL) {
    printf("Current working dir: %s\n", cwd);
  }
  return 0;
}