#include<stdio.h>
#include<stdlib.h>
#include"dependencies/files/files.h"
#include"dependencies/tokenizer/tokenizer.h"
#include"dependencies/HashMap/HashMap.h"
#include"dependencies/Initializer/initialize.h"

void printToken(struct token* TokenList,int TokenLen){

    struct hashMap MainMap=CreateHashMap();
    printf("printfile\n");
    for(int i=0;i<TokenLen;i++){

        switch (TokenList[i].type)
        {
        case text:
        printf("Text ");

        int val=-1;
        if(!InList(TokenList[i].value,TokenList[i].wordsize,MainMap,&val)){
            InsertLiteral(TokenList[i].value,TokenList[i].wordsize,&MainMap,i);
            printf("NotInList ");
        }
        else{
            printf("inList %d ", val);
        }
            break;

        case string:
            printf("String ");
            break;

        case literal:
            printf("Literal ");
            break;

         case equals:
            printf("Equals(==) ");
            break;

        case assing:
            printf("Assing(=) ");
            break;

        case openParenthesis:
            printf("OpenP( ");
            break;

        case closeParenthesis:
            printf("CloseP) ");
            break;

        case openFunct:
            printf("OpenFunct{ ");
            break;

        case closeFunct:
            printf("CloseFunct} ");
            
            break;

        case endLine:
            printf("EndLine(;) ");
            break;

        case rightshift:
            printf("RShift>> ");
            break;

        case graterorequal:
            printf("GreaterE>=");
            break;

        case greater:
            printf("Greater > ");
            break;

        case leftshift:
            printf("Lshift<< ");
            break;

        case lessorequal:
            printf("LessorEqual<= ");
            break;

        case less:
            printf("Less< ");
            break;

        case add:
            printf("Add ");
            break;
        
        case number:
            printf("Number %d ",TokenList[i].wordsize);
            break;

        case subTextReturn:
            printf("Return ");
            break;

        case subTextAssembly:
            printf("Assembly ");
            break;
        }
        

        

         printf("%d-- ",i);
         
        for(int j=0;TokenList[i].type!= number&&j<TokenList[i].wordsize;j++){
           
            printf("%c",TokenList[i].value[j]);
        }
        printf("\n");
    }
    DestroyMap(&MainMap);
}

int main(int argc, char const *argv[])
{
    Initialize();
    char* File;
    long long FileLen;
    int TokenLen=0;
    
    if (argc<2){
        printf("No file argument");
        exit(-1);
    }
    
    File=openfile(argv[1],&FileLen);
    struct token* TokenList=Tokenize(File,FileLen,&TokenLen);
    free(File);
    printToken(TokenList,TokenLen);

    
    return 0;
}
