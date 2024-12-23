#include"../nodeList/nodes.h"
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
    struct type* SubTypes;
    hashMap NameHashMap;
    
};

struct function{

};

#endif
