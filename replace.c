#include <stdio.h>
#include <string.h>

void *strReplace(char *str, char *replaceChar, char *data) {
    char *p;
    char tmp[1024 + 1];

    // 文字列 String の先頭から文字列 From を検索
    while( NULL != (p = strstr(str, replaceChar)) ){
        // 文字列 To を複写
        *p = '\0'; /* 元の文字列を旧文字列の直前で区切って */
        p += strlen(replaceChar);  /* ポインタを旧文字列の次の文字へ */
        strcpy(tmp, p);             /* 旧文字列から後を保存 */
        strcat(str, data);  /* 新文字列をその後につなぎ */
        strcat(str, tmp);   /* さらに残りをつなぐ */
    }
}

int main( void ) {
    char replaceStr[100];
    char baseStr[100];
    char endDate[20];

    memset(replaceStr, 0x00, sizeof(replaceStr));
    strcpy(replaceStr, "### END_DATE ###");
    memset(baseStr, 0x00, sizeof(baseStr));
    strcpy(baseStr, "2014/10/29 - ### END_DATE ###");
    memset(endDate, 0x00, sizeof(endDate));
    strcpy(endDate, "2014/11/29");

    strReplace(baseStr, replaceStr, endDate);
    printf( "AFTER=[%s]\n", baseStr);

    return 0;
}
