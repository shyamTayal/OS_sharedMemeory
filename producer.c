/*THIS IS THE PRODUCER PROCESS*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <unistd.h>
#define BUFFERSIZE 4
struct studentInfo
{
    char name[100];
    char roll[100];
    int age;
    char section[100];
};

typedef struct
{
    int in;
    int out;
    int prid;
    int cnid;
    struct studentInfo buffer[BUFFERSIZE];
} mydata;

void my_handler() {}

int main()
{
    printf("Producer Program Started...\n");
    signal(SIGUSR1, my_handler);
    int status;
    int shmid;
    int i;
    mydata *data;
    key_t key;
    key = ftok("empty.txt", 11);
    if (key < 0)
    {
        perror("error0:");
        exit(1);
    }
    shmid = shmget(key, sizeof(mydata), IPC_CREAT | 0666);
    if (shmid < 0)
    {
        perror("error1:");
        exit(1);
    }
    data = (mydata *)shmat(shmid, NULL, 0);
    if (data == (void *)-1)
    {
        perror("error2:");
        exit(1);
    }

    data->prid = getpid();
    data->in = 0;
    do
    {
        i = data->in;
        printf("Enter Student Information :\n");
        printf("Name : ");
        scanf("%s", (data->buffer[i]).name);
        printf("Roll Number : ");
        scanf("%s", (data->buffer[i]).roll);
        printf("Age : ");
        scanf("%d", &(data->buffer[i]).age);
        printf("Section : ");
        scanf("%s", (data->buffer[i]).section);
        data->in = data->in + 1;
        kill(data->cnid, SIGUSR1);
        pause();
    } while (i < BUFFERSIZE - 1);

    printf("Consumer Program Exting...\n");
}