#include "comment.h"
#include "stdlib.h"
#include "string.h"

Comment* createComment(char* username,char* content){
    Comment* thecomment=(Comment*)malloc(sizeof(Comment));
    if (!thecomment) return NULL;


    thecomment->username=(char*)malloc(strlen(username)+1);
    if (!thecomment->username){
        free(thecomment);
        return NULL;
    }
    strcpy(thecomment->username,username);

    thecomment->content=(char*)malloc(strlen(content)+1);
    if (!thecomment->content){
        free(thecomment->username);
        free(thecomment);
        return NULL;
    }
    strcpy(thecomment->content, content);

    thecomment->replies=NULL;
    thecomment->next=NULL;
    return thecomment;
}