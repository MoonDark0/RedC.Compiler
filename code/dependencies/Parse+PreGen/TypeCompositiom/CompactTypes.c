#include"compactTypes.h"
#include<stdlib.h>
#include<stdio.h>
#include"../Mainparse.h"
#include"../../tokenizer/tokenizer.h"

static int Insert(struct type** TokenList,int* MaxTypes, int* CurrentTypes, struct type Type){
    TokenList[0][*CurrentTypes]=Type;
    *CurrentTypes=*CurrentTypes+1;
    return *CurrentTypes-1;
}

//BAD CODE
struct type* readTypes(struct token* TokenList,int TokenLen){
    struct hashMap typeHash = CreateHashMap();//FOR TYPE LOOKUPS
    struct hashMap NameHash = CreateHashMap();//FOR NAME LOOKUPS

    struct hashMap NULLMAP={0,0,NULL,NULL,NULL};

    //MALLOC THE TYPELIST
    struct type* TypeList=malloc(sizeof(struct type)*4);
    if(TypeList==NULL){
        printf("FailedAlloc");
        exit(-1);
    }
    int MaxTypes=4;
    int CurrentTypes=0;

    //CREATE INT type(POS0) and INT(INT) (POS1)
    if(1){
    
    //Define Type Intiger
    struct type Intiger;
    Intiger.size=1;
    Intiger.type=Typeintiger;
    Intiger.lenght=0;
    Intiger.SubTypes=NULL;
    Intiger.NameHashMap=NULLMAP;
    
    //InsertIt
    int IntVal=Insert(&TypeList,&MaxTypes,&CurrentTypes,Intiger);

    //Check for it beeing at Pos 0
    if (IntVal!=0){
        printf("FatalError");
        exit(-1);
    }

    //Include in typeSpace
    InsertLiteral("int",sizeof("int"),&NameHash,IntVal);
    

    //StartInt(Int) ftp

    struct type MainFunction;
    MainFunction.size=1;
    MainFunction.type=Typefunctionpointer;
    MainFunction.lenght=3;
    MainFunction.NameHashMap=NULLMAP;

    //MALLOC Basic identifier
    MainFunction.SubTypes=malloc(sizeof(int)*3);

    //Check successful allocation
    if (MainFunction.SubTypes==NULL){
        printf("FatalError");
        exit(-1);
    }

    //Build the identifier(type functionPointer, returns int, args int)
    enum typeTypes FTP=Typefunctionpointer;
    MainFunction.SubTypes[0]=FTP;
    MainFunction.SubTypes[1]=IntVal;
    MainFunction.SubTypes[2]=IntVal;

    //InsertIt
    int FTINT=Insert(&TypeList,&MaxTypes,&CurrentTypes,MainFunction);
    //Insert to typeHash
    InsertLiteral((char*)MainFunction.SubTypes,sizeof(int)*MainFunction.lenght,&typeHash,FTINT);
    //Check
    if (FTINT!=1){
        printf("FatalError");
        exit(-1);
    }
    }


    for(int i=0;i<TokenLen;i++){

    }
    return TypeList;
}