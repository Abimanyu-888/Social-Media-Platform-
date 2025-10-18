#include "reply.h"
#include <stdlib.h>
#include <string.h>

Reply* createReply(char* username,char* content){
    Reply* thereply=(Reply*)malloc(sizeof(Reply));
    if (!thereply) return NULL;

    thereply->username=(char*)malloc(strlen(username)+1);
    if (!thereply->username){
        free(thereply);
        return NULL;
    }
    strcpy(thereply->username, username);

    thereply->content=(char*)malloc(strlen(content)+1);
    if (!thereply->content){
        free(thereply->username);
        free(thereply);
        return NULL;
    }
    strcpy(thereply->content, content);

    thereply->next=NULL;
    return thereply;
}