#include "IZN2.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum { BUF_LENGTH = 100*1024*1024 };


int search(char* buf)
{
    int i=0;
    int count=0;
    int maxcount=0;
    while (buf[i]!='\0')
    {
        if (( (int)buf[i] > 47) && ( (int)buf[i] < 58 ))
        {
            count++;
        }
        else{
            if (count>maxcount)
            {
                maxcount=count;
            };
            count=0;
        }
        i++;
    }
    return maxcount;

}

void readFile(char* buf, const char* fileName){
    FILE *f = fopen(fileName, "r");

    //seek eof position
    fseek(f, 0, SEEK_END);
    //get position => num of chars
    long fsize = ftell(f);
    fseek(f, 0, SEEK_SET);

    fread(buf, 1, fsize, f);
    fclose(f);

    //set last char to /0
    buf[fsize] = 0;
}

int main() {
    char *buffer = malloc(BUF_LENGTH);

    readFile(buffer,"../text.txt");

    //printf("%s", buffer);

    clock_t t;
    t = clock();
    int res=search(buffer);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

    printf("%d", res);
    printf(" %f", time_taken);


    free(buffer);
    return 0;
}
