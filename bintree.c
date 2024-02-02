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
    return 0;
}