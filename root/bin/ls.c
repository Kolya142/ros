#include <stdlib.h>
#include <stdio.h>
#include "../lib/rosl.c"

int main(int argc, char* argv[]) {
    char* cmd = (char*)malloc(128);
    if (argc == 2) {
        sprintf(cmd, "ls ./root%s", rtch_fn_decoder(argv[1]));
    }
    else {
        sprintf(cmd, "ls ./root");
    }
    system(cmd);
}