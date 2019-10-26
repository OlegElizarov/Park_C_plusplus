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
