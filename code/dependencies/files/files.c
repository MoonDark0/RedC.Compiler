#include<stdio.h>
#include<stdlib.h>
#include"files.h"

char* openfile(const char* name,long long* len){
    FILE* ToCompile=fopen(name,"r");
    if (ToCompile==NULL){
        printf("  No file named \" %s \" ",name);
        exit(-1);

    }
    
    int chars=0;
    int maxchars=1;
    char* filearray=malloc(sizeof(char));
    if(filearray==NULL){
        printf("FailedAlloc");
        exit(-1);
    }
    char ch;
    while((ch=fgetc(ToCompile))!=EOF){
        filearray[chars]=ch;
        chars++;
        if(chars==maxchars){
            maxchars*=2;
            filearray=realloc(filearray,maxchars*sizeof(char));
            if(filearray==NULL){
                printf("FailedAlloc");
            exit(-1);
            }
        }
    }

    *len=chars;
    return filearray;


}

void writeFile(char* output, char* file, long long len){

}
