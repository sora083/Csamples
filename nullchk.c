#include <stdio.h>
#include <string.h>

void main(void) {

    char str[20];

    memset(str, 0x00, sizeof(str));
   
    if (str == NULL) {
        prinf("STR is NULL");
    } else {
        printf("STR=%s\n", str);
    }
}
