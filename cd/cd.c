#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv) {

  if (argc != 2) {
	  printf("Please specify correct arguments\n");
	  return 1;
  }

  char buffer[100];

  printf("Origin directory is %s\n", getcwd(buffer, 100));

  int result = chdir(argv[1]);

  if (result != 0) {
	  printf("Cannot change directory to \'%s\'\n", argv[1]);
  } else {
	  printf("OK!\n");
  }

  printf("Changed directory is %s\n", getcwd(buffer, 100));



  return 0;
}
