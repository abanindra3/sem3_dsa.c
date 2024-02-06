#include <stdio.h>
#include <stdlib.h>

struct tree{
    struct tree* right;
    struct tree* left;
    int data;
};
struct tree* create(int data){
    struct tree* new=(struct tree*)malloc(sizeof(struct tree));
    new->data=data;
    new->right=NULL;
    new->left=NULL;
    return new;
}

struct tree* insert(struct tree* root,int val){
    if(root==NULL){
        return create(val);
    }else if(root->data>val){
        root->right=insert(root->right,val);
    }else if(root->data<val){
        root->left=insert(root->left,val);
    }
    return root;
}
struct tree* search(struct tree* root,int val){
    if(root==NULL){
        return root;
    }else if(root->data>val){
        search(root->right,val);
    }else if(root->data<val){
        search(root->left,val);
    }

}
void inorder(struct tree* root){
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right);
}

struct tree* min(struct tree* root){
    struct tree* curr=root;
    while(curr->left!=NULL){
        curr=curr->left;
    }
    return curr;
}

struct tree* delete(struct tree* root,int val){
    if(root==NULL){
        return root;
    }
    if(root->data>val){
        root->right=delete(root->right,val);
    }else if(root->data<val){
        root->left=delete(root->left,val);
    }else{
        if(root->left==NULL){
            struct tree* temp=root->right;
            free(root);
            return temp;
        }else if(root->right==NULL){
            struct tree* temp=root->left;
            free(root);
            return temp;
        }
        struct tree* temp=min(root->right);
        temp->data=root->data;
        delete(root->right,temp->data);
    }
    return root;
}
int main(){
    int inp;
    struct tree*root=NULL;
    printf("BINARY TREE PROGRAM");
    printf("ENTER ROOT VALUES--- / -1 TO STOP");
    while(1){
        scanf("%d",&inp);
        if(inp==-1){
            break;
        }
        root=insert(root,inp);
    }
    printf("In-order traversal of the BST: ");
    inorder(root);
    printf("\n");
    int del;
    printf("ENTER VALUE TO DELETE");
    scanf("%d",&del);
    root=delete(root,del);
    int key;
    printf("In-order traversal of the BST: ");
    inorder(root);
    printf("\n");
    printf("ENTER VALUE TO SEARCH");
    scanf("%d",&key);
    struct tree* res = search(root, key);
    if (res == NULL) {
        printf("NOT FOUND\n");
    } else {
        printf("FOUND\n");
    }
    return 0;
}
