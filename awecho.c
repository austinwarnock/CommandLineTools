#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){

    for(int i = 1; i < argc; ++i){
        fprintf(stdout, "%s ", argv[i]);
    }
    fprintf(stdout, "\n");
}
