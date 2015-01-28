#include<stdio.h>
#include<string.h>

#define MAXLEN 14

char *insComma(int num, char *str) {
    int  i, j = 0; // 書き込んだ桁数
    int  keta, minus = 0;
    char *p = str;
    int  tmp;

    /* 下位から順に数字を取り出し3桁の区切りに,を入れる */
    i = keta = 0;
    if( num < 0 ) {
        num = -num;
        minus = 1;
    }
    do {
        str[i++] = num % 10 + '0';
        keta++;
        num /= 10;
        if( keta % 3 == 0 && num != 0 ) {
            str[i++] = ',';
        }
    } while( num != 0 && i < MAXLEN );

    if( minus ) {
        str[i++] = '-';
    }
    str[i] = '\0';

    j = i-1;
    for( i = 0; j > i; i++, j-- ) {
        tmp =  str[i];
        str[i] = str[j];
        str[j] = tmp;
    }
}

int main(void) {
    int i = 1234;
    char insertedNum[10];

    memset(insertedNum, 0x00, sizeof(insertedNum));
    insComma(i, insertedNum);
    printf("insComma: %s\n", insertedNum);
}
