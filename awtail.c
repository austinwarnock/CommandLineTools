#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int get_file_size(FILE* fp){
    fseek(fp, 0, SEEK_END);
    int SIZE = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    return SIZE;
}

int get_lc(FILE* fp, int n){
    int c;
    int count = 0;
    int lines[get_file_size(fp)];

    for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n'){
            lines[count] = ftell(fp); 
            count = count + 1;
        }

    int offset = count > n ? lines[count-n-1] : 0;

    fseek(fp, offset, SEEK_SET);
    return count;
}

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

    if (fp == NULL)
        fp = stdin;

    get_lc(fp, line_count);

    char * line = NULL;
    size_t count = 0;
    size_t len = 0;
    while ((getline(&line, &len, fp)) != -1 && count < line_count) {
        printf("%s", line);
        count++;
    }

    fclose(fp);

    return 1;
    
}
