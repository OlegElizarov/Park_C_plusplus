#include "IZN2.h"
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

void* lin_search(char* buf,int begin,int end,int *res)
{
    int count=0;
    int maxcount=0;
    int i=begin;

    while (buf[i]!='\0' && i<=end)
    {
        if (isdigit(buf[i]))
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
