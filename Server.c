#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <zconf.h>

#define SHMSZ  27
main() {
    char c;
    int shmid;
    key_t key;
    char *sharedMemory, *s;
    char message[5];

    key = 5678;
    if ((shmid = shmget(key, SHMSZ , IPC_CREAT | 0666)) < 0) {
        exit(1);
        printf("shmget error");}

    if ((sharedMemory = shmat(shmid, NULL, 0)) == (char *) -1) {
        printf("shmat error");
        exit(1);
    }

    s = sharedMemory;
    char * ss;
    ss=sharedMemory;
    while(*ss!=NULL){
        //putchar(*ss);
        *ss=NULL;
        ss++;
    }

    for (;;){
        printf("\nmessage: ");
        scanf("%s",&message);
        //printf("msg %s\n",msg);
        int i =0;
        while (message[i]!='\0'){
            *s=message[i];
            s++;
            i++;
        }

        sleep(1);
        while(*s==NULL){}
        for (int i=0;i<5;i++){
            putchar(*s);
            s++;
        }
        sleep(1);
    }
}
