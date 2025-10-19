#include "platform.h"
#include "stdlib.h"
#include "string.h"

Platform* createPlatform(){
    Platform* theplatform=(Platform*)malloc(sizeof(Platform));
    if(!theplatform) return NULL;

    theplatform->head=NULL;
    theplatform->last_viewed=NULL;
    theplatform->post_count=0;
    return theplatform;
}

bool addPost(Platform* platform, char* username, char* caption){
    Post* thepost=createPost(username,caption);
    if(!thepost) return false;

    if(!platform->head){
        platform->head=thepost;
    }
    else{//head contains the most reacently added post
        thepost->next=platform->head;
        platform->head->prev=thepost;
        platform->head=thepost;
    }
    platform->post_count++;
    return true;
}
bool deletePost(Platform* platform, int n){
    if(n<1 || n>platform->post_count) return false;
    Post* toDelete=platform->head;
    while(--n){
        toDelete=toDelete->next;
    }
    if(toDelete==platform->head){
        platform->head=toDelete->next;
        if(platform->head) platform->head->prev=NULL;
    }
    else{
        toDelete->prev->next=toDelete->next;
        if(toDelete->next) toDelete->next->prev=toDelete->prev;
    }
    if(toDelete==platform->last_viewed){
        platform->last_viewed=platform->head;
    }
    freePost(toDelete);
    platform->post_count--;
    return true;
}
Post* viewPost(Platform* platform, int n){
    if(n<1 || n>platform->post_count) return NULL;
    Post* thepost=platform->head;
    while(--n){
        thepost=thepost->next;
    }
    platform->last_viewed=thepost;
    return thepost;
}
Post* currPost(Platform* platform){
    return platform->last_viewed;
}
Post* nextPost(Platform* platform){
    if(!platform->last_viewed) return NULL;
    if(platform->last_viewed->next)
        platform->last_viewed=platform->last_viewed->next;
    return platform->last_viewed;
}
Post* previousPost(Platform* platform){
    if(!platform->last_viewed) return NULL;
    if(platform->last_viewed->prev) 
        platform->last_viewed=platform->last_viewed->prev;
    return platform->last_viewed;
}

bool addComment(Platform* platform, char* username, char* content){
    Post* thepost=platform->last_viewed;
    Comment* thecomment=createComment(username,content);
    if(!thecomment) return false;

    thecomment->next=thepost->comments;
    thepost->comments=thecomment;
    return true;
}
bool deleteComment(Platform* platform, int n){
    Post* thepost=platform->last_viewed;
    if (!thepost) return false;

    Comment* toDelete=thepost->comments;
    while(--n && toDelete){
        toDelete=toDelete->next;
    }
    if(!toDelete) return false;
    freeComment(toDelete);
    return true;
}
Comment* viewComments(Platform* platform){
    Post* thepost=platform->last_viewed;
    if (!thepost) return NULL;
    return thepost->comments;
}

bool addReply(Platform* platform, char* username, char* content, int n){
    Post* thepost=platform->last_viewed;
    if (!thepost) return false;

    Comment* thecomment=thepost->comments;
    while(--n && thecomment){
        thecomment=thecomment->next;
    }
    if(!thecomment) return false;

    Reply* thereply=createReply(username,content);
    if(!thereply) return false;
    
    thereply->next=thecomment->replies;
    thecomment->replies=thereply;
    return true;
}
bool deleteReply(Platform* platform, int n, int m){
    Post* thepost=platform->last_viewed;
    if (!thepost ) return false;
    Comment* thecomment=thepost->comments;
    while(--n && thecomment){
        thecomment=thecomment->next;
    }
    if(!thecomment) return false;

    Reply* thereply=thecomment->replies;
    while(--m && thereply){
        thereply=thereply->next;
    }
    if(!thereply) return false;

    freeReply(thereply);
    return true;
}

void freeReply(Reply* toDelete){
    free(toDelete->username);
    free(toDelete->content);
}
void freeComment(Comment* toDelete){
    free(toDelete->username);
    free(toDelete->content);
    Reply* reply=toDelete->replies;
    while(reply){
        Reply* next=reply->next;
        freeReply(reply);
        reply=next;
    }
}
void freePost(Post* toDelete){
    free(toDelete->username);
    free(toDelete->caption);
    Comment* comment=toDelete->comments;
    while (comment)
    {
        Comment* next=comment->next;
        freeComment(comment);
        comment=next;
    }
}
void freePlatform(Platform* platform){
    Post* post=platform->head;
    while(post){
        Post* next=post->next;
        freePost(post);
        post=next;
    }
}