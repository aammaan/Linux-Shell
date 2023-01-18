#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include <dirent.h>
int main(int hello,char *hello1[]){
   
    if(strcmp(hello1[0],"")==0){
        struct dirent *point;
        DIR *directry = opendir(".");
        if(hello1[1]==NULL){
            if(directry == NULL){
                printf("Current Directory can'nt be accessed..!");
            }
            int counnt =0;
            while((point = readdir(directry))!=  NULL && counnt<1){
                if((point->d_name)[0]!='.'){
                    printf("\033[0;36m %s \033[0m ",point->d_name);
                }    

            }
        }
    }else if(strcmp(hello1[0],"-a")==0){
        struct dirent *point;
        DIR *directry = opendir(".");
        if(hello1[1]==NULL){
            if(directry == NULL){
                    printf("Current Directory can'nt be accessed..!");
                }
                int counnt =0;
                while((point = readdir(directry))!=  NULL && counnt<1){
                    printf("\033[0;36m %s \033[0m ",point->d_name);
                    printf("\n");
            }
            closedir(directry);

        }
        
    }else if(strcmp(hello1[0],"-d")==0){
        printf(".");
        
    }
    

}
