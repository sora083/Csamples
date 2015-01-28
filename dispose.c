#include<stdio.h>
#include <string.h>

int main(void) {
    float f = 100.11;
    double d = 100.11;
    double l = 123.1100;
    //double l = 1234567100.11015;

    long p = 2;

    printf("FLOAT=%f\n", f);
    printf("DOUBLE=%lf\n", d);
    printf("DOUBLE2=%.lf%d\n", d, p);
    printf("DOUBLE3=%.14g\n", l);

    char msg[20];
    memset(msg, 0x00, sizeof(msg));
    sprintf(msg,"%%d:%s","sora");
    printf("msg is %s\n", msg, p);

}
