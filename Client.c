#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#define SHMSZ  27
main() {
    int shmid;
    key_t key;
    char *sharedMemory, *s;
    char message[10];
    key = 5678;

    if ((shmid = shmget(key, SHMSZ , 0666)) < 0) {
        printf("shmget error");
        exit(1);
    }

    if ((sharedMemory = shmat(shmid, NULL, 0)) == (char *) -1) {
        printf("shmat error");
        exit(1);
    }

    s = sharedMemory;
    char * tempr;
    tempr=sharedMemory;
    while(*tempr!=NULL){
        *tempr=NULL;
        tempr++;
    }

    while(1){
        while(*s==NULL){}

        for (int i=0;i<5;i++){
            putchar(*s);
            s++;

        }
        sleep(1);
        printf("\nmessage: ");
        scanf("%s",&message);

        int i =0;
        while (message[i]!='\0'){
            *s=message[i];
            s++;
            i++;
        }
        sleep(1);
    }
    exit(0);
}
