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

int get_lc(FILE* fp){
    fseek(fp, 0, SEEK_SET);
    int c;
    int count = 0;

    for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n')
            count = count + 1;
        
    return count;
}

FILE* open_file(char* filename){
    FILE *fp;
    fp = fopen(filename, "rb");
    if (fp == NULL)
        fp = stdin;

    return fp;
}

int main(int argc, char *argv[]){
    FILE *fp;
    int opt;
    int c_flag, l_flag = 0;

    while ((opt = getopt(argc, argv, "lch")) != -1) {
        switch (opt) {
            case 'l':
                l_flag = 1;
                break;
            case 'c':
                c_flag = 1;
                break;
            case 'h':
                printf("usage: awwc [ l | c ] <filename>\n");
                break;
            case '?':
                fprintf(stderr, "Unknown option: -%c\n", optopt);
                return EXIT_FAILURE;
        }
    }

    fp = open_file(argv[optind]);


    if (c_flag && l_flag)
         fprintf(stdout, "\t%d\t%d\n", get_file_size(fp), get_lc(fp));
    else if (c_flag)
        fprintf(stdout, "%d\n", get_file_size(fp));
    else if (l_flag)
        fprintf(stdout, "%d\n", get_lc(fp));



}
