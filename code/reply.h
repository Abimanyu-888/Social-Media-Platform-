#ifndef REPLY_H
#define REPLY_H

typedef struct Reply{
    char* username;
    char* content;
    Reply* next;
}Reply;
Reply* createReply(char* username,char* content);
#endif