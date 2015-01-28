#include<stdio.h>

int main() {
    int i;

    for (i=0; i<3 && i<5; i++) {
    //for (i=0; i<5 || i<1; i++) {
        printf("num (i): %d\n", i);
    }
}
