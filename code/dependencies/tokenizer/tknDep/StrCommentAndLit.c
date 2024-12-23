#include<stdio.h>
#include<stdlib.h>
#include"StrCommentAndLit.h"
#include"../tokenizer.h"

void CommentText(int* first,long long len,const char* str){
    for(int i=*first+2;i<len-1;i++){
        if(str[i]=='*' && str[i+1]=='/'){
            *first=i+2;
            return;
        }
    }
    printf("WARNING:LeftOpenComment");
    *first=len;
}

struct token CreateString(int* first,long long len,const char* str){

    for(int i=*first+1;i<len;i++){
        if(str[i]=='"'){
            struct token Temp=CloseToken(*first+1,i,str,string);
            *first=i+1;
            return Temp;
        }
    }

    printf("ERROR:LeftOpenString");
    exit(-1);

    struct token Error={"Error",0,0};
    return Error;
}

struct token CreateLiteral(int* first,long long len,const char* str){

    if(((len-*first)>2)&&str[*first+2]=='\''){
        struct token Temp=CloseToken(*first+1,*first+2,str,literal);
            *first=*first+3;
            return Temp;
    }

    if(((len-*first)>3)&&str[*first+1]=='\\'&&str[*first+3]=='\''){
        struct token Temp=CloseToken(*first+1,*first+3,str,literal);
            *first=*first+4;
            return Temp;
    }

    printf("ERROR:InvalidLiteral");
    exit(-1);
    struct token Error={"Error",0,0};
    return Error;
}




struct token CreateText(int* first,long long len,const char* str){
    char isNum=0;
    int val=0;
    if(*first<len && str[*first]>('0'-1) && str[*first]<('9'+1)){
        isNum=1;
    }
    for(int i=*first;i<len;i++){

        switch (str[i])
        {

        case '/':
        case '"':
        case '\'':
        case '=':
        case '(':
        case ')':
        case '{':
        case '}':
        case ';':
        
        case '>':
        case '<':
        case '+':
        /*
        case '[':
        case ']':
        
        
        
        case '-':
        case '*':
        case '%':
        case '&':
        case '|':
        case '!':
        case '~':
        
        case '#':
        */
        case '\t':
        case '\n':
        case ' ':
            
            if(isNum){
            struct token Temp={NULL,val,number};
            *first=i;
            return Temp;
            }

            struct token Temp=CloseToken(*first,i,str,text);
            *first=i;
            return Temp;

            break;

        
        default:
            if(isNum){
                if(!(str[i]>('0'-1) && str[i]<('9'+1))){
                    printf("InvalidNumber");
                    exit(-1);
                }
                val*=10;
                val=val+str[i]-'0';
            }
            break;
        }



    }

    if(isNum){
        struct token Temp={NULL,val,number};
        *first=len;
        return Temp;
    }

    struct token Temp=CloseToken(*first,len,str,text);
    *first=len;
    return Temp;
}


