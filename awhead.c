#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]){

    FILE *fp;
    int opt;
    int line_count = 10;

    while ((opt = getopt(argc, argv, "n:")) != -1) {
        switch (opt) {
            case 'n':
                line_count = atoi(optarg);
                break;
            case '?':
                fprintf(stderr, "Unknown option: -%c\n", optopt);
                return EXIT_FAILURE;
        }
    }
    
    fp = fopen(argv[optind], "rb");
    if (fp == NULL && argc != optind){
        fprintf(stderr, "No such file or directory %s\n", argv[optind]);
        exit(-1);
    }


    char * line = NULL;
    size_t count = 0;
    size_t len = 0;
    while ((getline(&line, &len, (fp == NULL ? stdin : fp))) != -1 && count < line_count) {
        printf("%s", line);
        count++;
    }

    if (argc != optind)
        fclose(fp);

    return 1;
    
}
