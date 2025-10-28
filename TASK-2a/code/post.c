#include "post.h"
#include <stdlib.h>
#include <string.h>

Post* createPost(char* username, char* caption) {
    Post* thepost=(Post*)malloc(sizeof(Post));
    if (!thepost) return NULL;

    thepost->username=(char*)malloc(strlen(username)+1);
    if (!thepost->username){
        free(thepost);
        return NULL;
    }
    strcpy(thepost->username, username);
    
    thepost->caption=(char*)malloc(strlen(caption)+1);
    if (!thepost->caption){
        free(thepost->username);
        free(thepost);
        return NULL;
    }
    strcpy(thepost->caption, caption);

    thepost->comments=NULL;
    thepost->next=NULL;
    thepost->prev=NULL;
    return thepost;
}
