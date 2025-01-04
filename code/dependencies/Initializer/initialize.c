#include "../tokenizer/tknDep/SubText.h"
#include"../Parse+PreGen/TypeCompositiom/compactTypes.h"
#include "initialize.h"
#include<stdio.h>


void Initialize(){
    InitializeTokenChecking();
    readTypes(NULL,0);
    printf("successful init");
    return;
}