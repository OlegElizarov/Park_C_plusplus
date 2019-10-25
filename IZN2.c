#include "IZN2.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <mach/machine.h>
#include <stdatomic.h>


#define MAX_THREAD 4

pthread_mutex_t lock;

enum { BUF_LENGTH = 100*1024*1024 };

typedef struct Args_tag {
    int i;
    char* buf;
    int end;
    int *res;
} someArgs_t;

long fsize=0;
boolean_t costyl=FALSE;
atomic_int lastcount=0;


void* lin_search(char* buf,int begin,int end,int *res)
{

    int count=0;
    int maxcount=0;
    int i=begin;

    while (buf[i]!='\0' && i<=end)
    {
        if (( (int)buf[i] > 47) && ( (int)buf[i] < 58 ))
        {
            count++;
        }
        else{
            count=0;
        }
        i++;
        if (count>maxcount)
        {
            maxcount=count;
        };
    }

    *res=maxcount;
}


void* search(void *args)
{
    pthread_mutex_lock(&lock);
    someArgs_t *arg=(someArgs_t*) args;
    int count=0;
    int maxcount=0;
    int i=arg->i;
    int end=arg->end;
    char* buf=arg->buf;
    int *res=arg->res;
    if (costyl){
        count=lastcount;
    }
    while (buf[i]!='\0' && i<=end)
    {
        if (( (int)buf[i] > 47) && ( (int)buf[i] < 58 ))
        {
            count++;

            lastcount++;
        }
        else{
            count=0;
            lastcount=0;
            costyl=FALSE;
        }
        if (count>maxcount)
        {
            maxcount=count;
        };
        i++;
    }
    if ((( (int)buf[end] > 47) && ( (int)buf[end] < 58 ))||((buf[end]=='\n')&&(((int)buf[end-1])>47)&&((int)buf[end-1])<58))
    {
        costyl=TRUE;
        //lastcount--;
    }
    *res=maxcount;
    pthread_mutex_unlock(&lock);
}

void readFile(char* buf, const char* fileName){
    FILE *f = fopen(fileName, "r");

    //seek eof position
    fseek(f, 0, SEEK_END);
    //get position => num of chars
    fsize = ftell(f);
    fseek(f, 0, SEEK_SET);
    printf("%s %ld ","symbol count:",fsize);
    fread(buf, 1, fsize, f);
    fclose(f);

    //set last char to /0
    buf[fsize] = 0;
}

int main() {
    pthread_mutex_init(&lock, NULL);
    char *buffer = malloc(BUF_LENGTH);
    int res[4];
    readFile(buffer,"../text.txt");
    //printf("%s", buffer);
    clock_t t,timer;
    t = clock();
    printf("\n");
    printf("%s \n","Linear search");
    //for (int i = 0; i < 2; ++i) {
        lin_search(buffer, 0, fsize, &res[0]);
        timer = clock() - t;
        t=clock();
        double time_taken = ((double) timer) / CLOCKS_PER_SEC; // in seconds
        //printf("%d ",i);
        printf("%d ", res[0]);
        printf(" %f \n", time_taken);
    //}

    someArgs_t args[4];
    pthread_t threads[MAX_THREAD];
    printf("%s","Threads \n");
    t = clock();
    for (int i = 0; i < MAX_THREAD; i++) {
        args[i].buf=buffer;
        args[i].i=(i * fsize / 4)  +1;
        if (i==0)
        {
            args[i].i=0;
        }
        args[i].end=((fsize) * (i + 1) / 4);
        args[i].res=&res[i];
        pthread_create(&threads[i], NULL, search, (void *) &args[i]);
        timer = clock() - t;
        t=clock();
        double time_taken = ((double) timer) / CLOCKS_PER_SEC; // in seconds
        printf("%d %f \n",i,time_taken);

    }
    // joining 4 threads i.e. waiting for all 4 threads to complete

    for (int i = 0; i < MAX_THREAD; i++)
        pthread_join(threads[i], NULL);

    int max=0;
    // adding sum of all 4 parts
    for (int i = 0; i < MAX_THREAD; i++)
    {
        if (res[i]>max)
        max=res[i];
        printf("%s %d %d \n","Result of thread",i,res[i]);
    }
    printf("%s %d","Max is:",max);
    pthread_mutex_destroy(&lock);

    free(buffer);
    return 0;
}
