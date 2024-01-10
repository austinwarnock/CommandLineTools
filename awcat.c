#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    FILE *fp;
    const int BUFFER_SIZE = 4096;
    char buffer[BUFFER_SIZE];
    int currentFileIndex = (argc > 1 ? 1: 0);

    while (currentFileIndex < argc){
        if (argc > 1){
            fp = fopen(argv[currentFileIndex], "rb");
            if (fp == NULL){
                fprintf(stderr, "No such file or directory %s\n", argv[argc-1]);
                exit(-1);
            }
        } 

        while(fgets(buffer, BUFFER_SIZE, (fp == NULL ? stdin : fp))){
            int length = strlen(buffer);
            buffer[length - 1] = '\0';
            fprintf(stdout, "%s\n", buffer);
        }
    
        fclose(fp);
        ++currentFileIndex;
    }

    return 0;
}
