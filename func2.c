#include "IZN2parall.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <stdatomic.h>
#include <stdbool.h>
#include <ctype.h>

pthread_mutex_t lock;

enum { BUF_LENGTH = 100*1024*1024 };

typedef struct Args_tag {
    int i;
    int end;
    int *res;
    char* buf;

} someArgs_t;

atomic_long  fsize=0;
bool costyl=false;
atomic_int lastcount=0;

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
        if (isdigit(buf[i]))
        {
            count++;

            lastcount++;
        }
        else{
            count=0;
            lastcount=0;
            costyl=false;
        }
        if (count>maxcount)
        {
            maxcount=count;
        };
        i++;
    }
    if (isdigit(buf[i]))
    {
        costyl=true;
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
