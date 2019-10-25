#include "IZN2.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <mach/machine.h>
#include <stdatomic.h>

pthread_mutex_t lock;

enum { BUF_LENGTH = 100*1024*1024 };

typedef struct Args_tag {
    int i;
    char* buf;
    int end;
    int *res;
} someArgs_t;

atomic_long  fsize=0;
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