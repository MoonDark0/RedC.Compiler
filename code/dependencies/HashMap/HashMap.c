#include "HashMap.h"
#include<stdio.h>
#include<stdlib.h>

//IMPLEMENT VALUES

struct hashMap CreateHashMap(){
    struct hashMap mainMap;
    mainMap.elements=0;
    mainMap.MaxElement=4;
    mainMap.Lenghts=calloc(mainMap.MaxElement,sizeof(int));
    mainMap.strings=malloc(mainMap.MaxElement*sizeof(char*));
    mainMap.Values=malloc(mainMap.MaxElement*sizeof(int));
    if(mainMap.Lenghts==NULL || mainMap.strings==NULL || mainMap.Values==NULL){
        printf("FailedAlloc");
        exit(-1);
    }
    return mainMap;
    
}

void ReHash(struct hashMap* Map){
    int NewMaxElements=Map->MaxElement*4;
    int* NewLenghts=calloc(NewMaxElements,sizeof(int));
    char** NewStrings=malloc(NewMaxElements*sizeof(char*));
    int* NewValues=malloc(NewMaxElements*sizeof(int));

    if(NewLenghts==NULL || NewStrings==NULL || NewValues==NULL){
        printf("FailedAlloc");
        exit(-1);
    }
    for(int i=0;i<Map->MaxElement;i++){
        if(Map->Lenghts[i]!=0){

            int Len=Map->Lenghts[i];
            long long sum=0;
            
            for(int j=0;j<Len;j++){
                sum+=Map->strings[i][j]*(131+29*j);
            }

            int hash=sum&(NewMaxElements-1);
            while(NewLenghts[hash]!=0){
                hash=(hash+1)&(Map->MaxElement-1);
            }
            NewLenghts[hash]=Len;
            NewStrings[hash]=Map->strings[i];
            NewValues[hash]=Map->Values[i]; 
        }
    }
    free(Map->strings);
    free(Map->Lenghts);
    free(Map->Values);
    Map->strings=NewStrings;
    Map->Lenghts=NewLenghts;
    Map->Values=NewValues;
    Map->MaxElement=NewMaxElements;
    return;
}

void InsertLiteral(char* str,int len,struct hashMap* Map,int val){

    if(Map->MaxElement==0){
        printf("Inserted To inexisting map");
        exit(-1);
    }

    if(len==0){
        printf("Invalid Element");
    }

    long long charsum=0;
    int i=0;
    while(i<len){
        charsum+=str[i]*(131+29*i);
        i++;
    }
    int hash=charsum&(Map->MaxElement-1);

    while(Map->Lenghts[hash]!=0){
        hash=(hash+1)&(Map->MaxElement-1);
    }

    Map->Lenghts[hash]=len;
    Map->Values[hash]=val;
    Map->strings[hash]=malloc(len*sizeof(char));
    if(Map->strings[hash]==NULL){
        printf("FailedAlloc");
        exit(-1);
    }

    for(i=0;i<len;i++){
        Map->strings[hash][i]=str[i];
    }

    Map->elements=Map->elements+1;
    
    if (Map->MaxElement==Map->elements*4){
        ReHash(Map);
    }
 
    return;
    
}

int InList(char* str,int len,struct hashMap Map,int*Val){
     if(Map.MaxElement==0){
        printf("LookedAt inexisting map");
        exit(-1);
    }

     if(len==0){
        printf("Invalid Element");
    }

    long long charsum=0;
    int i=0;
    while(i<len){
        charsum+=str[i]*(131+29*i);
        i++;
    }
    int hash=charsum&(Map.MaxElement-1);
    while(1){
        if(Map.Lenghts[hash]==0){
        return 0;
        }

        if(Map.Lenghts[hash]==len){

        for(int i=0;i<len+1;i++){
            if (i==len){
                *Val=Map.Values[hash];
                return 1;   
            }
            if (str[i]!=Map.strings[hash][i]){
                i=len+3;
            }
        }
      
        }

        hash=(hash+1)&(Map.MaxElement-1);
    }

    
}

int ChangeVal(char* str,int len,struct hashMap Map,int Val){
    if(Map.MaxElement==0){
        printf("Changed At inexisting map");
        exit(-1);
    }
    printf("DON'T USE CHANGEVAL");

}

void DestroyMap(struct hashMap* Map){
    if(Map->MaxElement==0){
        printf("Empty Map Delete");
        exit(-1);
    }
    for(int i=0;i<Map->elements;i++){
        if(Map->Lenghts[i]!=0){
            free(Map->strings[i]);
        }
    }
    free(Map->Values);
    free(Map->Lenghts);
    Map->strings=NULL;
    Map->Values=NULL;
    Map->Lenghts=NULL;
    Map->MaxElement=0;
    return;
}