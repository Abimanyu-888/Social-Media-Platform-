#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

#define NOT_COVERED 0
#define COVERED_BUT_NO_PHONE 1
#define HAS_PHONE 2

typedef struct node{
    struct node* left;
    struct node* right;
}node;

node* createNode() {
    struct node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
node* create_family_tree(int* data,int n){
    if (n==0 || data[0]==0) return NULL;
    node* queue[n];
    int front=0;
    int rear=0;
    node* root=createNode();
    queue[rear++]=root;
    int i=1;
    while(front!=rear && i<n){
        node* curr=queue[front++];
        if(i<n && data[i++]==1){
            curr->left=createNode();
            queue[rear++]=curr->left;
        }
        if(i<n && data[i++]==1){
            curr->right=createNode();
            queue[rear++]=curr->right;
        }
    }
    return root;
}
int minPhone(node* root,int* phoneCount){
    if(root==NULL) return COVERED_BUT_NO_PHONE;
    int left=minPhone(root->left,phoneCount);
    int right=minPhone(root->right,phoneCount);
    
    if(left==NOT_COVERED || right==NOT_COVERED){
        (*phoneCount)++;
        return HAS_PHONE;
    }
    if(left==HAS_PHONE || right==HAS_PHONE) return COVERED_BUT_NO_PHONE;

    return NOT_COVERED;
}   
int main(){
    int n;
    printf("Enter length of array (n):");
    scanf("%d",&n);

    int* data=(int *)malloc(sizeof(int)*n);
    printf("Enter the level order:");
    for(int i=0;i<n;i++){
        scanf("%d",data+i);
    }

    node* root=create_family_tree(data,n);

    int MinPhoneRequired=0;
    minPhone(root,&MinPhoneRequired);
    printf("MIN NO OF PHONES:%d\n",MinPhoneRequired);
}