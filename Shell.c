#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include<pthread.h>
void *threadexec(void *two){
    char *aman=(char *)two;
    system(aman);
    return NULL;
    
}

void heading(){
    printf("\033[0;31m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    printf("    \033[0;36m     Welcome to Aman's Shell                 ");
    printf("\033[0;31m\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \033[0m \n\n\n");

}
void pwd(){
    char a[999];
    if(getcwd(a, sizeof(a)) !=   NULL)   {
        printf("%s\n",a);
    }else{
        perror("Pwd");
    }
}
void echo(char *str,int size){
    if(str[5]== '"'){
        for(int i = 6;i<size-2;i++){
            printf("%c",str[i]);
        }
    }else{
        for(int i = 4;i<size;i++){
            printf("%c",str[i]);
        }
    }
  printf("\n");
}
void cd(char *str){
   char *hi=NULL;
   hi = str;
    int a=chdir(hi);
    if(a==-1){
        printf("Error..!!!\n");
    }
}
int checck(char * dir){
        DIR* directory = opendir(dir);
        if(directory != NULL){
            closedir(directory);
            return 0;
        }
        else if(errno == ENOTDIR){
            return 1;
        }else{
            return -1;

        }
    }

int main(){
heading();
while(7){
    char input[100];
    printf("\033[0;32m>>> \033[0m");
    fgets(input,100,stdin);
    int len = strlen(input);
    char *third = strtok(input," \n");
    char *first=third;
    char *second=third;
    char *forth=third;
    char *fifth = third;
    second= strtok(NULL," \n");
    third = strtok(NULL," \n");
    forth = strtok(NULL," \n");
    fifth = strtok(NULL," \n");



    // if(strcmp(first,"&t")==0 || strcmp(second,"&t")==0 || strcmp(third,"&t")==0 || strcmp(forth,"&t")==0 || strcmp(fifth,"&t")==0 ){// function to call &t
    //     int checky=0;
    //     char empty[]="";

    //     if(strcmp(first,"&t")==0){
    //         checky=1;


    //     }else if(strcmp(second,"&t")==0){
            
    //         checky =2;
    //         strcat(empty,first);
    //         strcat(empty," ");
    //         pthread_t one;
    //         int op;
    //         printf("%s",empty);
    //         op = pthread_create(&one, NULL,threadexec,empty); 

    //         op=pthread_join(one,NULL); 


    //     }else if(strcmp(third,"&t")==0){
    //         checky =3;
    //         strcat(empty,first);
    //         strcat(empty," ");
    //         strcat(empty,second);
    //         strcat(empty," ");
    //          pthread_t one;
    //         int op;

    //         op = pthread_create(&one, NULL,threadexec,empty); 

    //         op=pthread_join(one,NULL); 

    //     }else if(strcmp(forth,"&t")==0){
    //         checky =4;
    //         strcat(empty,first);
    //         strcat(empty," ");
    //         strcat(empty," ");
    //         strcat(empty,third);
    //         strcat(empty," ");
    //          pthread_t one;
    //         int op;

    //         op = pthread_create(&one, NULL,threadexec,empty); 

    //         op=pthread_join(one,NULL); 

    //     }else if(strcmp(fifth,"&t")==0){
    //         checky =5;

    //         strcat(empty,first);
    //         strcat(empty," ");
    //         strcat(empty,second);
    //         strcat(empty," ");
    //         strcat(empty,third);
    //         strcat(empty," ");
    //         strcat(empty,forth);
    //         strcat(empty," ");
    //          pthread_t one;
    //         int op;

    //         op = pthread_create(&one, NULL,threadexec,empty); 

    //         op=pthread_join(one,NULL); 

    //     }
    
    // }else{




    if(strcmp(first,"pwd")==0){ // funtion to call pwd
    if(second == NULL){
      
        pwd();
    }else{
            printf("Sorry '%s' command is not handled for pwd!\n",second);

    }

    }else if(strcmp(first,"echo")==0){ //funtion to call different command in echo

        if(len>5){
            if(strcmp(second,"*")==0){ // function to perform echo * (prints all current directories)
                struct dirent *point;
                DIR *directry = opendir(".");
                if(directry == NULL){
                    printf("Current Directory can'nt be accessed..!");
                }
                int counnt =0;
                while((point = readdir(directry))!=  NULL && counnt<1){
                    printf("\033[0;36m %s \033[0m ",point->d_name);
                    // printf("\n");
                }
                closedir(directry);
                printf("\n");
            }else if(strcmp(second,"-n")==0){ // function to perform echo -n (runs to next shell in same line)
                if(input[8]=='"'){
                    for(int i = 9;i<len-2;i++){
                    printf("%c",input[i]);
                    }
                }else{
                    for(int i = 7;i<len-1;i++){
                        printf("%c",input[i]);
                    }
                }
            }else{
                echo(input,len); // calling of echo funtion

            }
        }


    }else if(strcmp(first,"cd")==0){ // funcion to call pcd
    if(second ==NULL){
        printf("No directory is given\n");
    }else{
        if(checck(second)==-1){
            printf("No such directry exist!\n");
        }else{
            cd(second);
        }
    }

    }else if(strcmp(first,"ls")==0){ //function to call ls

   
        if(second == NULL){ // function to call ls
            pid_t pid= fork();
            if(pid ==0){
                execl("/home/aman/ls",NULL);
            }else if(pid>0){
                wait(NULL);
            }else if(pid<0){
                printf("Error in assigning value to fork!");
            } 
            printf("\n");
        }else if(strcmp(second,"-a")==0){ // funcion to call ls -a
            pid_t pid= fork();
            if(pid ==0){
                execl("/home/aman/ls","-a",NULL);
            }else if(pid>0){
                wait(NULL);
            }else if(pid<0){
                printf("Error in assigning value to fork!");
            }
            printf("\n");
        }else if(strcmp(second,"-d")==0){ // funtion to call ls -d
            pid_t pid= fork();
            if(pid ==0){
                execl("/home/aman/ls","-d",NULL);
            }else if(pid>0){
                wait(NULL);
            }else if(pid<0){
                printf("Error in assigning value to fork!");
            }
            printf("\n");
        }else{
            printf("Sorry '%s' command is not handled for ls!\n",second);

        }

        
    }else if(strcmp(first,"mkdir")==0){// function to call mkdir

        if(second == NULL){ // function to call normal mrdir
            pid_t pid1= fork();
            if(pid1 ==0){
                execl("/home/aman/mkdir",NULL);
            }else if(pid1>0){
                wait(NULL)   ;
            }else if(pid1<0){
                printf("Error in assigning value to fork!");
            
            }
            printf("\n");
        }else if(strcmp(second,"-v")==0){ // function to call -v
            pid_t pid1= fork();
            if(pid1 ==0){
                execl("/home/aman/mkdir","-v",third,NULL);
            }else if(pid1>0){
                wait(NULL)   ;
            }else if(pid1<0){
                printf("Error in assigning value to fork!");
            }
            printf("\n");
        }else if(strcmp(second,"-p")==0){ // funtion to call -p
            pid_t pid1= fork();
            if(pid1 ==0){
                execl("/home/aman/mkdir","-p",third,NULL);
            }else if(pid1>0){
                wait(NULL)   ;
            }else if(pid1<0){ 
                printf("Error in assigning value to fork!");
                printf("\n");
            }
        }else{
            printf("Sorry '%s' command is not handled for mkdir!\n",second);

        }
    }else if(strcmp(first,"rm")==0){// function to call rm
        if(strcmp(second,"-i")!=0 && strcmp(second,"-r")!=0){
            if(third == NULL){
                pid_t pid3= fork();
                if(pid3 ==0){
                    execl("/home/aman/rm",second,NULL);
                }else if(pid3>0){
                    wait(NULL)   ;
                }else if(pid3<0){
                    printf("Error in assigning value to fork!");
                
                }
            }else{
                pid_t pid3= fork();
                if(pid3==0){
                    execl("/home/aman/rm",second,third,NULL); //funtion to call rm for two files
                }else if(pid3>0){
                    wait(NULL)   ;
                }else if(pid3<0){
                    printf("Error in assigning value to fork!");
                
                }
            }  
        }else if(strcmp(second,"-i")==0){
            pid_t pid3= fork();
                if(pid3 ==0){
                    execl("/home/aman/rm",second,third,NULL); //funtion to call rm -i
                }else if(pid3>0){
                    wait(NULL)   ;
                }else if(pid3<0){
                    printf("Error in assigning value to fork!");
                
                }
        }else if(strcmp(second,"-r")==0){  //funtion to call rm -r
            pid_t pid3= fork();
                if(pid3 ==0){
                    execl("/home/aman/rm",second,third,NULL);
            int ch=0;
                }else if(pid3>0){
                    wait(NULL)   ;
                }else if(pid3<0){
                    printf("Error in assigning value to fork!");
                
                }
        }else{
            printf("Sorry '%s' command is not handled for rm!\n",second);
            
        }
        

    
    }else if(strcmp(first,"date")==0){ // function to call date
        if(second == NULL){            //funtion to call normal date
            pid_t pid3= fork();
            if(pid3 ==0){
                execl("/home/aman/date",NULL);
            int ch=0;
            }else if(pid3>0){
                wait(NULL)   ;
            }else if(pid3<0){
                printf("Error in assigning value to fork!");
            
            }
        }else if(strcmp(second,"-I")==0){ //function to call -I
            pid_t pid1= fork();
            if(pid1 ==0){
                execl("/home/aman/date","-I",NULL);
            }else if(pid1>0){
                wait(NULL)   ;
            }else if(pid1<0){
                printf("Error in assigning value to fork!");
            }
            printf("\n");
        }else if(strcmp(second,"-R")==0){
            pid_t pid1= fork();
            if(pid1 ==0){
                execl("/home/aman/date","-R",NULL);
            }else if(pid1>0){
                wait(NULL)   ;
            }else if(pid1<0){
                printf("Error in assigning value to fork!");
            }
            printf("\n");
        }else{
            printf("Sorry '%s' command is not handled for date!\n",second);
        }
    }else if(strcmp(first,"cat")==0){// function to call cat
        if(strcmp(second,"-n")!=0 &&  strcmp(second,"-E")!=0){            //funtion to call normal cat
            pid_t pid3= fork();
            if(pid3 ==0){
                execl("/home/aman/cat",second,NULL);
            int ch=0;
            }else if(pid3>0){
                wait(NULL)   ;
            }else if(pid3<0){
                printf("Error in assigning value to fork!");
            
            }
        }else if(strcmp(second,"-n")==0){            //funtion to call cat -n
            pid_t pid3= fork();
            if(pid3 ==0){
                execl("/home/aman/cat",second,third,NULL);
            int ch=0;
            }else if(pid3>0){
                wait(NULL)   ;
            }else if(pid3<0){
                printf("Error in assigning value to fork!");
            
            }
        }else if(strcmp(second,"-E")==0){            //funtion to call cat -E
            pid_t pid3= fork();
            if(pid3 ==0){
                execl("/home/aman/cat",second,third,NULL);
            int ch=0;
            }else if(pid3>0){
                wait(NULL)   ;
            }else if(pid3<0){
                printf("Error in assigning value to fork!");
            
            }
        }
    
    }else if(strcmp(first,"exit")==0){// function to call exit
        printf("\033[0;33m \n\n    Thankyou for your precious time \033[0;34m:)\033[0m \n\n\n\n\n");
        break;
    
    }else{
        printf("Sorry '%s' command is not handled for shell!\n",first);
    }
    }

}
// }
