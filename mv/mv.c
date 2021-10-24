// mv [option] Source Destination
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv){
    char buffer[1024];
    int files[2];
    ssize_t count;

    if (argc < 3){
      return -1;
    }
    files[0] = open(argv[1], O_RDONLY);
    if (files[0] == -1) {
      return -1;
    }        
    files[1] = creat(argv[2], 0777);
    if (files[1] == -1){
        close(files[0]);
        return -1;
    }
    while ((count = read(files[0], buffer, sizeof(buffer))) != 0){
      write(files[1], buffer, count);
    }
    remove(argv[1]);
    close(files[1]);
    close(files[0]);
    return 0;
}