#include"../HashMap/HashMap.h"

#ifndef MAINPARSE
#define MAINPARSE


enum typeTypes{
    Typeintiger,//JUST THE INT
    Typepointer,
    Typestructutre,
    Typefunctionpointer
};

struct type{
    enum typeTypes type;
    int size;
    int lenght;
    int* SubTypes; //(if type is fctp then array starts with 5;) 
    struct hashMap NameHashMap;
    
};



#endif
