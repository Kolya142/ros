#include "./root/lib/rosl.c"

int main() {
    printf("welcome to ros\nLoading /bin/sh\n");
    rtch_startfile("/bin/sh.c");
}