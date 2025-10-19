#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "platform.h"


Platform* socialMediaPlatform = NULL;
void print_replies(Reply* replies){
    if(!replies) return;
    print_replies(replies->next);
    printf("%s %s\n", replies->username, replies->content);
}
void print_comments(Comment* comments){
    if(!comments) return;
    print_comments(comments->next);
    printf("%s %s\n", comments->username, comments->content);
    print_replies(comments->replies);
}   


int main() {
    char command[500];
    char arg1[500], arg2[500], arg3[500];

    while (fgets(command, sizeof(command), stdin)) {
        // Remove trailing newline
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "create_platform") == 0) {
            if (socialMediaPlatform == NULL) {
                socialMediaPlatform = createPlatform();
            } 
            else {
                printf("Platform already exists.\n");
            }
        } 
        else if (socialMediaPlatform == NULL) {
            printf("Error: Platform not created. Please run 'create_platform' first.\n");
            continue;
        } 
        else if (sscanf(command, "add_post %s %s", arg1, arg2) == 2) {
            if (!addPost(socialMediaPlatform, arg1, arg2)) {
                printf("Failed to add post.\n");
            }
        } 
        else if (sscanf(command, "delete_post %s", arg1) == 1) {
            if (!deletePost(socialMediaPlatform, atoi(arg1))) {
                printf("Post does not exist.\n");
            }
        } 
        else if (sscanf(command, "view_post %s", arg1) == 1) {
            Post* p = viewPost(socialMediaPlatform, atoi(arg1));
            if (p) {
                printf("%s %s\n", p->username, p->caption);
            } else {
                printf("Post does not exist.\n");
            }
        } 
        else if (strcmp(command, "current_post") == 0) {
            Post* p = currPost(socialMediaPlatform);
            if (p) {
                printf("%s %s\n", p->username, p->caption);
            } else {
                printf("No current post or no posts exist.\n");
            }
        } 
        else if (strcmp(command, "next_post") == 0) {
            Post* p = nextPost(socialMediaPlatform);
             if (p) {
                printf("%s %s\n", p->username, p->caption);
            } else {
                printf("Next post does not exist.\n");
            }
        } 
        else if (strcmp(command, "previous_post") == 0) {
            Post* p = previousPost(socialMediaPlatform);
             if (p) {
                printf("%s %s\n", p->username, p->caption);
            } else {
                printf("Previous post does not exist.\n");
            }
        } 
        else if (sscanf(command, "add_comment %s %s", arg1, arg2) == 2) {
            if (!addComment(socialMediaPlatform, arg1, arg2)) {
                printf("Failed to add comment. Is there a post viewed?\n");
            }
        } 
        else if (sscanf(command, "delete_comment %s", arg1) == 1) {
            if (!deleteComment(socialMediaPlatform, atoi(arg1))) {
                printf("Comment does not exist.\n");
            }
        } 
        else if (strcmp(command, "view_comments") == 0) {
            Comment* comments = viewComments(socialMediaPlatform);
            if (comments) {
                print_comments(comments);
            } else {
                printf("No comments to show or no post viewed.\n");
            }
        } 
        else if (sscanf(command, "add_reply %s %s %s", arg1, arg2, arg3) == 3) {
            if (!addReply(socialMediaPlatform, arg1, arg2, atoi(arg3))) {
                printf("Failed to add reply.\n");
            }
        } 
        else if (sscanf(command, "delete_reply %s %s", arg1, arg2) == 2) {
            if (!deleteReply(socialMediaPlatform, atoi(arg1), atoi(arg2))) {
                printf("Reply does not exist.\n");
            }
        } 
        else if (strcmp(command, "exit") == 0) {
            break;
        } 
        else {
            if(strlen(command) > 0) {
                 printf("Unrecognized command: %s\n", command);
            }
        }
    }

    if (socialMediaPlatform) {
        freePlatform(socialMediaPlatform);
    }
}
