#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_seq(int N, int M){
    if(M == N)
        fprintf(stdout, "%d\n", M);

    if(M < N)
        for(int i = M; i <= N; ++i)
            fprintf(stdout, "%d\n", i);

    if(M > N)
        for(int i = M; i >= N; --i)
            fprintf(stdout, "%d\n", i);
}

int main(int argc, char *argv[]){
    switch(argc){
        case 1:
            fprintf(stderr,"Error must supply at least one argument\n");
            break;
        case 2:
            print_seq(atoi(argv[1]), 0);
            break;
        case 3:
            print_seq(atoi(argv[2]), atoi(argv[1]));
            break;
    }
}
