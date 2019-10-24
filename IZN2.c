#include "IZN2.h"
#include <stdio.h>
#include <stdlib.h>

enum { BUF_LENGTH = 100*1024*1024 };


int search(char* buf)
{
    int i=0;
    int count=0;
    while (buf[i]!='\n')
    {
        if (( (int)buf[i] > 47) && ( (int)buf[i] < 58 ))
        {
            count++;
        }
        i++;
    }
    return count;

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

    printf("%s", buffer);

    printf("%d", search(buffer));

    free(buffer);
    return 0;
}
