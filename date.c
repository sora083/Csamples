#include <stdio.h>
#include <time.h>

void main(void) {

    time_t timer;
    struct tm *now;
    char ymd[20];

    /* 現在時刻ﾉ取得 */
    time(&timer);

    /* 1日の秒数86400秒 * n日を引く */
    timer -= 86400;

    /* 時刻を構造体に変換 */
    now = localtime(&timer);

    /* 文字列に書き込む */
    sprintf(ymd, "%d%02d%02d", now->tm_year + 1900
            , now->tm_mon + 1
            , now->tm_mday);

    printf("YESTERDAY=[%s]\n", ymd);
}
