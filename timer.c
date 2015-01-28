#include <stdio.h>
#include <time.h>

int main(void) {
    time_t     timer;
    struct tm  *date;
    char    timestamp[256];

    time(&timer);
    printf("TIMER:%ld\n", timer);

    date = localtime(&timer);
    printf("DATE:%s\n", date);

    strftime(timestamp, 256, "%Y%m%d%H%M%S", date);
    printf("TIMESTAMP:%s\n", timestamp);

    return 0;
}
