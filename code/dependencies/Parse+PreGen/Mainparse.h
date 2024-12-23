#include"../HashMap/HashMap.h"

#ifndef MAINPARSE
#define MIANPARSE
enum typeTypes{
    intiger,//JUST THE INT
    pointer,
    structutre,
    array,
    functionpointer
};

struct type{
    typeTypes type;
    int size;
    int lenght;
    int* SubTypes; //(if type is fctp then array starts with 5;) 
    hashMap NameHashMap;
    
};

struct Expression{

};

struct function{
    struct type Type;
    struct Expression;
    int len;
    
};

#endif
