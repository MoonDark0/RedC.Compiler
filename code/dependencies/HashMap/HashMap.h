
#ifndef NODELISTWORDS
#define NODELISTWORDS

struct hashMap{
    int elements;
    int MaxElement;
    int* Lenghts;
    char** strings;
    int* Values;
};

struct hashMap CreateHashMap();
void InsertLiteral(char* str,int len,struct hashMap* Map,int val);
int InList(char* str,int len,struct hashMap Map,int*Val);
int ChangeVal(char* str,int len,struct hashMap Map,int Val);
void DestroyMap(struct hashMap* Map);


#endif