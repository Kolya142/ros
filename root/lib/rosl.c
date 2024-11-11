#ifndef rosl
#define rosl
#include <stdio.h>
#include <stdlib.h>
void rtch_startfile(char* filename) {
    char* cmd = (char*)malloc(128);
    sprintf(cmd, "tcc -run ./root%s", filename);
    system(cmd);
}
// WARNING: this function frees memory automatic if need
char* rtch_fn_decoder(char* filename) {
    if (filename[0] != '.' && filename[0] != '/' && filename[0] != '~') {
        char* filename_ = malloc(530);
        sprintf(filename_, "/bin/%s", filename);
        free(filename);
        return filename_;
    }
    if (filename[0] == '~') {
        char* filename_ = malloc(530);
        sprintf(filename_, "/user%s", filename+1);
        free(filename);
        return filename_;
    }
    return filename;
}

#endif