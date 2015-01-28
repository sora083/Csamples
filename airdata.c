#include<stdio.h>
#include <string.h>
#include <stdlib.h>

#define AIR_TOKEN ","

int main() {
    char str[100];
    char wk_go[100];
    char wk_back[100];
    int air_count;
    char *p_air;

    memset(str, 0x00, sizeof(str));
    memset(wk_go, 0x00, sizeof(wk_go));
    memset(wk_back, 0x00, sizeof(wk_back));
    strcpy(str, "2006/11/20, 601便,KMI(08:45),2006/11/21, 602便,KMI(07:30)");

    p_air = strtok(str, AIR_TOKEN);

    strcpy(wk_go, "");
    strcpy(wk_back, "");
    for (air_count = 1; p_air != '\0'; air_count++) {
        if ( (air_count>=1) && (air_count<=3)) {
            strcat(wk_go, p_air);
        } else if (air_count >= 4) {
            strcat(wk_back, p_air);
        }
        p_air = strtok('\0', AIR_TOKEN);
    }
    printf("GO  :%s\n", wk_go);
    printf("BACK:%s\n", wk_back);
}
