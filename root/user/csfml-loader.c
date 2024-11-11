#include "../lib/rosl.c"
#include <unistd.h>
#include <string.h>

int main() {
    printf("    please write csfml filename:\n    >");
    fflush(stdout);
    char* f = malloc(500);
    memset(f, ' ', 500);
    read(stdin, f, 500);
    scanf("%s", f);

    char* name = rtch_fn_decoder(f);
    char* cmd = malloc(1024);
    sprintf(cmd, "tcc ./root%s -o ./root/tmp/csfml-yes-this-system-not-for-compiling-but-i-have-only-one-way -lcsfml-graphics -lcsfml-window -lcsfml-system", name);
    system(cmd);
    system("./root/tmp/csfml-yes-this-system-not-for-compiling-but-i-have-only-one-way");
}