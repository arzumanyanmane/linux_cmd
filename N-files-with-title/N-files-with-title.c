//rm [OPTION]... FILE...
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

void prepare(){
    DIR* dir = opendir("files");
    if (dir) {
      printf("Directory exists.\n");
    } else if (ENOENT == errno) {
       mkdir("files", 0700);
    } else {
      printf("opendir() failed for some other reason. %d\n", errno); 
    }
}

int main(int argc, char **argv){
    int file;
    FILE *fptr;
    char *original_content = (char *) malloc(50);
    char *file_content = (char *) malloc(50);
    char *original_file_name = "files/file_%d";
    char *file_name = (char *) malloc(8);

    if (argc < 2){
        return -1;
    }
    prepare();
    if (argc == 3){
        original_content = argv[2];
        strcat(original_content, " %d");
    }
    char *file_num_char = argv[1];
    int file_num = atoi(file_num_char);

    for(int i = 1; i <= file_num; ++i){
        snprintf(file_content, 50, original_content, i);
        snprintf(file_name, 16, original_file_name, i);
        file = creat(file_name, 0777);
        fptr = fopen(file_name, "w");
        fprintf(fptr, "%s", file_content);
    }
    printf("%s", file_content);
    return 0;
}
