#include <stdio.h>
#include <string.h>

void main(void) {

    char str[20];
    memset(str, 0x00, sizeof(str));

    /* 文字列に書き込む */
    sprintf(str, "%s", "TEST1");
    printf("FIRST=[%s]\n", str);
    sprintf(str, "%s", "TEST2");
    printf("SECOND=[%s]\n", str);
}
