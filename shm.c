#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define __SHM_COMMON_H__

#define KEYFILE_PATH   "/home/sora/"
#define PROJ_CHAR      (char)'s'
#define SHMSIZE   (360)

int main(int argc, char *argv[]) 
{
    key_t  key; 
    int    shmid, shmid2;
    char   *shmaddr;
    char   str[100];

    memset(str, 0x00, sizeof(str));

    key = ftok(KEYFILE_PATH, PROJ_CHAR);
    printf("IPC KEY:%d\n", key);
    if ( key == -1 ) {
        perror("ftok()");
        return 1;
    }

    /*共有メモリの割り当て*/
    //shmid = shmget(key, SHMSIZE, 0 );
    shmid = shmget(key, SHMSIZE, IPC_CREAT| 0666 );
    printf("SHMID:%d\n", shmid);
    if ( shmid == -1 ) {
        perror("shmget()");
        return 1;
    }

    /*共有メモリのアタッチ*/
    shmaddr = shmat(shmid, NULL, 0);
    //sprintf(str, "%s", shmaddr);
    printf("SHMADDR:%s\n", shmaddr);
    if ( shmaddr == (char*)-1 ) {
        perror("shmat()");
        return 1;
    }

    /*共有メモリ初期値セット*/
    strcpy(shmaddr,"run");
    printf("'%s' is set up in the control code.\n",shmaddr);

    /*共有メモリの割り当て*/
    shmid2 = shmget(key, SHMSIZE, 0 );
    //shmid = shmget(key, SHMSIZE, IPC_CREAT| 0666 );
    printf("SHMID:%d\n", shmid2);
    if ( shmid2 == -1 ) {
        perror("shmget()");
        return 1;
    }

    /*共有メモリにセット*/
    strcpy(shmaddr,"log");
    sprintf(str, "%s", shmaddr);
    printf("key:%s\n", str);
    return 0;
}

