#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int main () {
    char str[1024];
    int len = 0;
    int len2 = 0;

    memset(str, 0x00, sizeof(str));
    strcpy(str, "aああああああああああいいいいいいいいいいうううううううううういいいいいいいいいいおおおおおおおおおおああああああああああいいいいいいいいいいうううううううううういいいいいいいいいいおおおおおおおおおおああああああああああいいいいいいいいいいうううううううううういいいいいいいいいいおおおおおおおおおおああああああああああいいいいいいいいいいうううううううううういいいいいいいいいいおおおおおおおおおお");

    len = strlen(str);
    len2 = mblen(str, sizeof(str));

    printf("[%s] size: len=(%d) len2=(%d)\n", str, len, len2);

    return 0;
}
