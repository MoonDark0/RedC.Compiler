#include"stdlib.h"
#include"SubText.h"
#include"../tokenizer.h"
#include"../../HashMap/HashMap.h"

static struct hashMap HashComparison;

void InitializeTokenChecking(){
    enum Types Type;
    HashComparison=CreateHashMap();

    Type=subTextReturn;
    InsertLiteral("return",sizeof("return")-1,&HashComparison,Type);

    Type=subTextBreak;
    InsertLiteral("break",sizeof("break")-1,&HashComparison,Type);

    Type=subTextStruct;
    InsertLiteral("struct",sizeof("struct")-1,&HashComparison,Type);

    Type=subTextIf;
    InsertLiteral("if",sizeof("if")-1,&HashComparison,Type);

    Type=subTextElif;
    InsertLiteral("elif",sizeof("elif")-1,&HashComparison,Type);

    Type=subTextElse;
    InsertLiteral("else",sizeof("else")-1,&HashComparison,Type);

    Type=subTextWhile;
    InsertLiteral("while",sizeof("while")-1,&HashComparison,Type);

    Type=subTextFor;
    InsertLiteral("for",sizeof("for")-1,&HashComparison,Type);

    Type=subTextSwitch;
    InsertLiteral("switch",sizeof("switch")-1,&HashComparison,Type);

    Type=subTextCase;
    InsertLiteral("case",sizeof("case")-1,&HashComparison,Type);

    Type=subTextDefault;
    InsertLiteral("default",sizeof("default")-1,&HashComparison,Type);

    Type=subTextTypeof;
    InsertLiteral("typeof",sizeof("typeof")-1,&HashComparison,Type);
    return;
}

void SubTextToken(struct token* Token){
    enum Types Ttype=text;
    int type=(int ) Ttype;
    if(InList(Token->value,Token->wordsize,HashComparison,&type)){
        free(Token->value);
        Token->wordsize=0;
    }
    Token->type=type;
    
    return;
}