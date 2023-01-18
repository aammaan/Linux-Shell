#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include <dirent.h>
int main(int hello, char *hello1[]){
    
    if(strcmp(hello1[0],"-n")!=0 && strcmp(hello1[0],"-E")!=0 ){  
        int fo;
        char text[3000];
        fo = open(hello1[0],O_RDONLY);
        int limit;
        if(fo!=-1){
            while((limit=read(fo,text,sizeof(text)))>0){
                printf("%s",text);
            }
        }else{
            printf("Error in opening file!");
        }
        return 0;
    }else if(strcmp(hello1[0],"-n")==0){  
        int fo;
        char text[3000];
        fo = open(hello1[1],O_RDONLY);
        int limit;
        int count=1;
        if(fo!=-1){
            printf("  1 ");
        count++;

            while(limit=read(fo,text,sizeof(text))>0){
                for(int i=0;i<strlen(text);i++){
                    if(text[i]=='\n'){
                        printf("%c  %d ",text[i],count);
                        count++;
                    }
                    else{
                        printf("%c",text[i]);
                    }
                    
                }
            }
        }else{
            printf("Error in opening file!");
        }
        return 0;
    }else if(strcmp(hello1[0],"-E")==0){  
        int fo;
        char text[3000];
        fo = open(hello1[1],O_RDONLY);
        int limit;

        if(fo!=-1){
            
            while(limit=read(fo,text,sizeof(text))>0){
                for(int i=0;i<strlen(text);i++){
                    if(text[i]=='\n'){
                        printf(" $  %c",text[i]);
                    }
                    else{
                        printf("%c",text[i]);
                    }
                    
                }
            }
        }else{
            printf("Error in opening file!");
        }
        return 0;
    }
}
