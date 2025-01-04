#ifndef TOKENIZER
#define TOKENIZER

enum Types{
    text,
    number,
    string,
    literal,
    equals,
    assing,
    openParenthesis,
    closeParenthesis,
    openFunct,//In reality braces, but because all braces do is structs and functions, i call them functions
    closeFunct,
    endLine,
    less,
    lessorequal,
    rightshift,
    greater,
    graterorequal,
    leftshift,
    add,
    pointer,






    //SUBTEXT TYPES

    subTextReturn,
    subTextBreak,
    subTextStruct,
    subTextIf,
    subTextElif,
    subTextElse,
    subTextWhile,
    subTextFor,
    subTextSwitch,
    subTextCase,
    subTextDefault,
    subTextTypeof,
    subTextNew,
    subTextAssembly,
    subTextNoWarn
};

struct token{
    char* value;
    int wordsize;
    enum Types type;
};


struct token* Tokenize(char* str,long long lenght,int* TokenListLenght);

struct token CloseToken(int first, int last,const char* str,enum Types enumType);
#endif