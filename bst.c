#include <stdio.h>
#include <stdlib.h>

struct tree{
    struct tree* left;
    struct tree* right;
    int data;
};

struct tree* create(int value){
    struct tree* new = (struct tree*)malloc(sizeof(struct tree));
    new->data=value;
    new->left=NULL;
    new->right=NULL;
    return new;
}

struct tree* insert(struct tree* root,int value){
    if(root==NULL){
        return create(value);
    }
    if(value<root->data){
        root->left= insert(root->left,value);
    }else if(value>root->data){
        root->right= insert(root->right,value);
    }
    return root;
}
void inorder(struct tree* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

struct tree* search(struct tree*root,int key){
    if(root==NULL || root->data==key){
        return root;
    }else if(key>root->data){
        search(root->right,key);
    }else{
        search(root->left,key);
    }
}
struct tree* findmin(struct tree* node){
    struct tree* curr=node;
    while(curr->left!=NULL){
        curr=curr->left;
    }
    return curr;
}
struct tree*delete(struct tree*root,int val){
    if(root==NULL){
        return root;
    }
    if(val>root->data){
        root->right= delete(root->right,val);
    }else if(val<root->data){
        root->left= delete(root->left,val);
    }else{
        if(root->left==NULL){
            struct tree*temp=root->right;
            free(root);
            return temp;
        }else if(root->right==NULL){
            struct tree*temp=root->left;
            free(root);
            return temp;
        }
        //two children
        struct tree* temp=findmin(root->right);
        temp->data=root->data;
        root->right=delete(root->right,temp->data);
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