#include "../lib/rosl.c"
#include <string.h>
#include <unistd.h>


int main() {
    printf("welcome to ros sh\n");
    char* cmd = malloc(500);
    while (1) {
        printf(">>>");
        fflush(stdout);
        memset(cmd, 0, 500);
        read(STDIN_FILENO, cmd, 500);
        if (cmd[0] == 'r' && cmd[1] == 's' && cmd[2] == 't' && cmd[3] == '!') {
            printf("______________\nrestarting /bin/sh.c\n");
            rtch_startfile("/bin/sh.c");
            exit(0);
        }
        cmd = rtch_fn_decoder(cmd);
        rtch_startfile(cmd);
    }
}