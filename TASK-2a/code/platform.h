#ifndef PLATFORM_H
#define PLATFORM_H
#include "post.h"
#include "stdbool.h"

typedef struct Platform{
    Post* head;
    Post* last_viewed;
    int post_count;
}Platform;

Platform* createPlatform();
void freePlatform(Platform* platform);

bool addPost(Platform* platform, char* username, char* caption);
bool deletePost(Platform* platform, int n);
Post* viewPost(Platform* platform, int n);
Post* currPost(Platform* platform);
Post* nextPost(Platform* platform);
Post* previousPost(Platform* platform);
void freePost(Post* toDelete);

bool addComment(Platform* platform, char* username, char* content);
bool deleteComment(Platform* platform, int n);
Comment* viewComments(Platform* platform);
void freeComment(Comment* toDelete);

bool addReply(Platform* platform, char* username, char* content, int n);
bool deleteReply(Platform* platform, int n, int m);
void freeReply(Reply* toDelete);

#endif