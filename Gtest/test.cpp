#include <gtest/gtest.h>
#include <cstddef>
#include <iostream>
extern "C" {
#include "../IZN2.h"
#include "../IZN2parall.h"
}


TEST(NULL,checklin_search)
{
    char buffer[1024];
    int res[1];
    int fsize=1024;
    for (int i = 0; i <1023 ; ++i) {
        buffer[i]=(char)(48+rand()%10);
    }
    buffer[1023]='\0';
    lin_search(buffer, 0, fsize, &res[0]);
    EXPECT_EQ(1023,res[0]);
}

TEST(NULL,checklin_search_max)
{
    char buffer[1024];
    int res[1];
    int fsize=1024;
    for (int i = 0; i <1023 ; ++i) {
        buffer[i]=(char)(48+rand()%75);
    }
    buffer[1023]='\0';
    lin_search(buffer, 0, fsize, &res[0]);
    EXPECT_LE(res[0],1022);
}
