#ifndef STRTOKEN
#define STRTOKEN

void CommentText(int* first,long long len,const char* str);

struct token CreateString(int* first,long long len,const char* str);

struct token CreateLiteral(int* first,long long len,const char* str);

struct token CreateText(int* first,long long len,const char* str);
#endif