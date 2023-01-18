#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include<string.h>
#include<unistd.h>
#include <sys/stat.h>
#include <unistd.h>
#include<time.h>
int main(int hello,char *hello1[]){
    if(strcmp(hello1[0],"")==0){
        time_t t;
        time(&t);
        printf("%s",ctime(&t));
        return 0;
    }else if(strcmp(hello1[0],"-I")==0){
        struct tm * one;
        time_t a;
        time(&a);
        one=localtime(&a);
        char out[245];
        strftime(out,245,"%Y-%m-%d  ",one);
        printf("%s",out);

    }else if(strcmp(hello1[0],"-R")==0){
        struct tm * tim;
        time_t a;
        time(&a);
        tim=localtime(&a);
        char out[245];
        strftime(out,245,"%a, %d %b %Y %X",tim);
        printf("%s +530",out);
    }
}
