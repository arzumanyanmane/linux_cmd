//list-recursively  PATH
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

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

void printDir(int depth, char* path) {
    char newPath[1000];
    DIR* directory = opendir(path);
    if(directory != NULL){
        struct dirent* struct_;
        while((struct_ = readdir(directory)) != NULL) {
            if(strcmp(struct_->d_name , "..") == 0 || strcmp(struct_->d_name , ".") == 0 || strcmp(struct_->d_name , ".git") == 0) {
                continue;
            }
            for(int i = 0; i < depth; ++i){
                printf("- ");
            }
            strcpy(newPath, path);
            strcat(newPath, "/");
            strcat(newPath, struct_->d_name);
            if(isRegular(newPath)) {
                printf("%s\n",struct_->d_name);  
            }
            else if(isDir(newPath)) {
                printf("[%s]\n",struct_->d_name);
                printDir(depth + 1, newPath);
            }
        }
    }
    closedir(directory);
}

int main(int argc, char **argv){
    char *path = (char *) malloc(20);
    if (argc < 2){
        path = "./";
    }else{
        path = argv[1];
    }
    if(isRegular(path)){
        printf("- %s", path);
    }
    if(isDir(path)){
        printDir(1, path);
    }
    return 0;
}
