#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include<string.h>
#include<unistd.h>
#include <sys/stat.h>
#include <unistd.h>
int main(int hello,char *hello1[]){
    if(strcmp(hello1[0],"")==0){
        printf("New Directory's name: ");
        int out = 0;
        char name[22];
        scanf("%s,",name);
        out = mkdir(name,0755);
        if(out ==0){
            printf("Your Directory %s is successsfully created!",name);
        }else{
            printf("Sorry, Error in creating Directory named %s !",name);
        }
        return 0;
    }else if(strcmp(hello1[0],"-v")==0){
        int out1=0;
  
        out1 = mkdir(hello1[1],0755);
        if(out1 ==0){
            printf("mkdir: Created Directory: '%s' ",hello1[1]);
        }else{
            printf("Sorry, Error in creating Directory named %s !",hello1[1]);

        }

    }else if(strcmp(hello1[0],"-p")==0){
        char *sec = strtok(hello1[1],"/");
        char *fir = sec;
        sec = strtok(NULL," ");
      
        chdir(fir);
        int out2=0;
        out2 = mkdir(sec,0755);
        if(out2 !=0){
            printf("Sorry, Error in creating Directory named %s !",sec);
        }

        // int out1=0;
  
        // out1 = mkdir(hello1[1],0755);
        // if(out1 ==0){
        //     printf("mkdir: Created Directory: '%s' ",hello1[1]);
        // }else{
        //     printf("Sorry, Error in creating Directory named %s !",hello1[1]);

        // }

    }
}
