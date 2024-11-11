#include "../lib/rosl.c"
#include <string.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    if (argc != 2 && argc != 3) {
        printf("usage: curl.c <url> or curl.c <url> <dist>\n");
        exit(0);
    }
    if (!strcmp(argv[0], "help")) {
        printf("curl.c runs tcc program from url\n");
        exit(0);
    }
    if (argc == 2) {
        printf("runs %s\n", argv[1]);
        fflush(stdout);
        char* cmd = (char*)malloc(128);
        sprintf(cmd, "curl %s -o ./root/tmp/curl-cache.c", argv[1]);
        int err = system(cmd);
        if (err != 0) {
            printf("curl errors with %d\n", err);
            exit(0);
        }
        printf("starting %s, press ^C to exit to sh\n", argv[1]);
        usleep(600000);
        rtch_startfile("/tmp/curl-cache.c");
    }
    if (argc == 3) {
        char* o = rtch_fn_decoder(argv[2]);
        printf("downloads %s to %s\n", argv[1], o);
        fflush(stdout);
        char* cmd = (char*)malloc(128);
        sprintf(cmd, "curl %s -o %s", argv[1], o);
        int err = system(cmd);
        if (err != 0) {
            printf("curl errors with %d\n", err);
            exit(0);
        }
    }
}