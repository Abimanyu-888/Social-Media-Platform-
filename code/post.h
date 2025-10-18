#ifndef POST_H
#define POST_H
#include "comment.h"
typedef struct Post{
    char* username;
    char* caption;
    Comment* comments;
    Post* next;
    Post* prev;
}Post;
Post* createPost(char* username, char* caption);
#endif