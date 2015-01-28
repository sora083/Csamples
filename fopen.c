#include<stdio.h>

#include "fopen.h"

int main() {

    FILE *fp;
    char buf[256];

    //fp = fopen(TMP_DIR"sora.txt", "r");
    fp = fopen("sora.txt", "r");
    if (fp == NULL) {
        printf("file open error!!\n");
        return -1;
    }

    while (fgets(buf, 256, fp) != NULL) {
        printf("%s", buf);
    }
    fclose(fp);
}
