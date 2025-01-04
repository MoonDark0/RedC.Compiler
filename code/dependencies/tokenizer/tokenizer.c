#include<stdio.h>
#include<stdlib.h>
#include"tokenizer.h"
#include"tknDep/StrCommentAndLit.h"
#include"tknDep/SubText.h"




struct token CloseToken(int first, int last, const char* str,enum Types enumType){
    int lenght=last-first;

    struct token NewToken;
    char* TokenString=malloc(lenght);
    for(int i=first;i<last;i++){
        TokenString[i-first]=str[i];
    }
    NewToken.value=TokenString;
    NewToken.wordsize=lenght;
    NewToken.type=enumType;


    return NewToken;
}

static struct token* Insert(struct token* Tokenlist,int* TokenNum,int* MaxToken,struct token add){
    Tokenlist[*TokenNum]=add;
    *TokenNum=*TokenNum+1;
    if(*TokenNum==*MaxToken){
        *MaxToken=*MaxToken*2;
        struct token* TKTemp=realloc(Tokenlist,sizeof(struct token)*(*MaxToken));
        if(TKTemp==NULL){
            printf("FailedAllocation");
            exit(-1);
        }
        Tokenlist=TKTemp;
    }
    return Tokenlist;
}



struct token* Tokenize(char* str,long long lenght,int* TokenListLenght){
    int TokenNum=0;
    int MaxTokens=1;
    struct token* Tokens=malloc(sizeof(struct token));
    if(Tokens==NULL){
        printf("FailedAllocation");
        exit(-1);
    }

    int pointer=0;

    while(pointer<lenght){
        int allowDouble=0;
        if((lenght-pointer)!=0){
            allowDouble=1;
        }

        switch (str[pointer])
        {


        //COMENT AND DIVISION


        case '/':

            if(allowDouble && str[pointer+1]=='*'){
                CommentText(&pointer,lenght,str);
            }
            else{
                printf("notImplemented");
                exit(-1);
                //AddDivision
            }
            break;



        //STR


        case '"':
            Tokens=Insert(Tokens,&TokenNum,&MaxTokens,CreateString(&pointer,lenght,str));
            break;
        

        //LITERAL

        case '\'':
            Tokens=Insert(Tokens,&TokenNum,&MaxTokens,CreateLiteral(&pointer,lenght,str));
            break;


        

        //EQUALS and ASSING

        case '=':

            if(allowDouble && str[pointer+1]=='='){
                struct token Equals={NULL,0,equals};
                Tokens=Insert(Tokens,&TokenNum,&MaxTokens,Equals);
                pointer+=2;
            }
            else{
                struct token Assign={NULL,0,assing};
                Tokens=Insert(Tokens,&TokenNum,&MaxTokens,Assign);
                pointer++;
            }

            break;

        //BRACKETOPEN
        case '(':
            struct token OpenParenthesis={NULL,0,openParenthesis};
            Tokens=Insert(Tokens,&TokenNum,&MaxTokens,OpenParenthesis);
            pointer++;
            break;


        //BRACKETCLOSE
        case ')':
            struct token CloseParenthesis={NULL,0,closeParenthesis};
            Tokens=Insert(Tokens,&TokenNum,&MaxTokens,CloseParenthesis);
            pointer++;
            break;

        //FUNCTIONOPEN

        case '{':
            struct token OpenFunct={NULL,0,openFunct};
            Tokens=Insert(Tokens,&TokenNum,&MaxTokens,OpenFunct);
            pointer++;
            break;


        //FUNCTIONCLOSE
        case '}':
            struct token CloseFunct={NULL,0,closeFunct};
            Tokens=Insert(Tokens,&TokenNum,&MaxTokens,CloseFunct);
            pointer++;
            break;

        //ENDLINE
        case ';':
            struct token EndLine={NULL,0,endLine};
            Tokens=Insert(Tokens,&TokenNum,&MaxTokens,EndLine);
            pointer++;
            break;

        

        

        //GREATER/GREATEREQUAL/SHIFT

        case '>':
            if(allowDouble && str[pointer+1]=='>'){
                struct token LeftShift={NULL,0,leftshift};
                Tokens=Insert(Tokens,&TokenNum,&MaxTokens,LeftShift);
                pointer+=2;
            }
            else if (allowDouble && str[pointer+1]=='=')
            {
                struct token GreaterE={NULL,0,graterorequal};
                Tokens=Insert(Tokens,&TokenNum,&MaxTokens,GreaterE);
                pointer+=2;
            }
            else{
                struct token Greater={NULL,0,greater};
                Tokens=Insert(Tokens,&TokenNum,&MaxTokens,Greater);
                pointer+=1;
            }
            

            break;


        //SMALLER/SMALLEREQUAL//SHIFT

        case '<':
            if(allowDouble && str[pointer+1]=='<'){
                struct token Rightshift={NULL,0,rightshift};
                Tokens=Insert(Tokens,&TokenNum,&MaxTokens,Rightshift);
                pointer+=2;
            }
            else if (allowDouble && str[pointer+1]=='=')
            {
                struct token SmallE={NULL,0,lessorequal};
                Tokens=Insert(Tokens,&TokenNum,&MaxTokens,SmallE);
                pointer+=2;
            }
            else{
                struct token Small={NULL,0,less};
                Tokens=Insert(Tokens,&TokenNum,&MaxTokens,Small);
                pointer+=1;
            }
            break;


            //ADD/INCREMENT
            case '+':
                 struct token Add={NULL,0,add};
                Tokens=Insert(Tokens,&TokenNum,&MaxTokens,Add);
                pointer+=1;
            break;

                //POINTER
            case '*':
                struct token Pointer={NULL,0,pointer};
                Tokens=Insert(Tokens,&TokenNum,&MaxTokens,Pointer);
                pointer+=1;
                break;

        //TODO

        /*
        //ARRAYOPEN
        case '[':
            //code
            break;
        
        //ARRAYCLOSE
        case ']':
            //code
            break;

        

        //SUB/UNARY-/DECREMENT
        case '-':
            //code
            break;

        
        //MOD
        case '%':
            //code
            break;
        
        //AND/BINARYAND
        case '&':
            //code
            break;

        //OR/BINARYOR
        case '|':
            //code
            break;

        //NOT/DOESN'TEQUAL
        case '!':
            //code
            break;

        
        //BINNOT
        case '~':
            //code
            break;
        

        //GLOBAL
        case '#':
            //code
            break;
        

        */

       


        //TAB
        case '\t':
        pointer++;
            break;


        //NEWLINE
        case '\n':
            pointer++;
            break;
            

        //SPACE
        case ' ':
            pointer++;
            break;

        
        default:
            struct token TextToken;
            TextToken=CreateText(&pointer,lenght,str);
            if(TextToken.type==text){
                SubTextToken(&TextToken);
            }
            Tokens=Insert(Tokens,&TokenNum,&MaxTokens,TextToken);
            break;
        }
    }
    *TokenListLenght=TokenNum;
    
    return Tokens;
}