#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include<string.h>
#include<unistd.h>
#include<dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include<errno.h>
int main(int hello,char *hello1[]){
    int check(char * dir){
        DIR* directory = opendir(dir);
        if(directory != NULL){
            closedir(directory);
            printf("rm cannot remove Directory!");

            return 0;
        }
        else if(errno == ENOTDIR){
            return 1;
        }else{
            return -1;

        }
    }

       if(strcmp(hello1[0],"-i")!=0 && strcmp(hello1[0],"-r")!=0){
        
        if(strcmp(hello1[0],"")!=0){
           
            if(check(hello1[0])==0){
                printf("rm cannot remove Directory!\n");
            }else{
                int i=0;
                i=remove(hello1[0]);
                if(i<0){
                    printf("rm:1 cannot remove %s : No such file or directory\n",hello1[0]);
                }
            }
        }
        if(strcmp(hello1[1]," ")!=0){
          
            if(check(hello1[1])==0){
                printf("rm cannot remove Directory!\n");
            }else{
                int i=0;
                i=remove(hello1[1]);
                if(i<0){
                    printf("rm:2 cannot remove %s : No such file or directory\n",hello1[1]);
                }
            }
        }
    }
    if(strcmp(hello1[0],"-i")==0){
       
        if(check(hello1[1])==0){
                printf("rm -i cannot remove Directory!");
        }else{
            printf("rm: Do you really want to remove '%s' ?",hello1[1]);
            char choice[5];
            scanf("%s",choice);
            if(choice[0]=='y'){
                int i=0;
                i = remove(hello1[1]);
                if(i<0){
                    printf("rm:3 cannot remove %s : No such file or directory\n",hello1[1]);
                }
            }
        }
    }
    if(strcmp(hello1[0],"-r")==0){

        int i=0;
        i = remove(hello1[1]);
        if(i<0){
            printf("rm:4 cannot remove %s : No such file or directory\n",hello1[1]);
        }
    }
}
