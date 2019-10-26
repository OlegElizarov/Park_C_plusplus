#include "IZN2.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <stdatomic.h>
#include "func2.c"
#include <unistd.h>

#define MAX_THREAD 4



int main(int argc,char *argv[]) {
    pthread_mutex_init(&lock, NULL);
    char *buffer = malloc(BUF_LENGTH);
    int res[4];
    readFile(buffer,argv[1]);
    clock_t t,timer;
    t = clock();

    printf("\n");
    printf("%s \n","Linear search");

    lin_search(buffer, 0, fsize, &res[0]);
    timer = clock() - t;
    t=clock();
    double time_taken = ((double) timer) / CLOCKS_PER_SEC; // in seconds
    printf("%d ", res[0]);
    printf(" %f \n", time_taken);

    someArgs_t args[4];
    pthread_t threads[MAX_THREAD];
    printf("%s","Threads \n");
    t = clock();

    for (int i = 0; i < MAX_THREAD; i++)
    {
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
        sleep(1);
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
    printf("\n");
    free(buffer);
    return 0;
}
