#include <stdio.h>
#include <string.h>

void main(void) {

    int iArray[20] = {};
    //int iArray[20];
    int sizeOfArray = 20;
    int size = 0;
    int i = 0;

    iArray[0] = 1;
    iArray[1] = 20;

    for(i=0; i<sizeOfArray; i++) {
        if(iArray[i] == 0) {
            break;
        } else {
            printf("array=%d\n", iArray[i]);
            size ++;
        }
    }

    printf("array size=%d\n", size);

}
