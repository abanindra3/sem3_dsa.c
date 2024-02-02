#include <stdio.h>
#include <stdlib.h>
struct avl{
    int data;
    struct avl* left;
    struct avl* right;
    int height;
};
int getheight(struct avl*node){
    if(node==NULL){
        return 0;
    }
    return node->height;
}

struct avl* create(int key){
    struct avl* new = (struct avl*)malloc(sizeof(struct avl));
    new->data=key;
    new->left=NULL;
    new->right=NULL;
    new->height=1;
    return new;
}
int max(int a,int b){
    return (a>b)?a:b;
}
struct avl*lr(struct avl* x){
    struct avl* y=x->right;
    struct avl*t2=y->left;

    y->left=x;
    x->right=t2;

    x->height = max(getheight(x->left), getheight(x->right)) + 1;
    y->height = max(getheight(y->left), getheight(y->right)) + 1;

    return y;
}

struct avl*rr(struct avl* y){
    struct avl* x=y->left;
    struct avl*t2=x->right;

    x->right=y;
    y->left=t2;

    y->height = max(getheight(y->left), getheight(y->right)) + 1;
    x->height = max(getheight(x->left), getheight(x->right)) + 1;

    //new root
    return x;
}
int bf(struct avl*root){
    if(root==NULL){
        return 0;
    }
    return (getheight(root->left)-getheight(root->right));
}

struct avl* insert(struct avl* root, int val){
    if(root==NULL){
        return create(val);
    }
    if(val>root->data){
        root=insert(root->right,val);
    }else if(val<root->data){
        root=insert(root->left,val);
    }else{
        return root;
    }
    root->height = 1 + max(getheight(root->left), getheight(root->right));
    int bal=bf(root);

    //ll
    if(bal>1 && val<root->left->data){
        return rr(root);

    }//rr
    else if(bal<-1 && val>root->right->data){
        return lr(root);

    }//lr
    else if(bal>1 && val>root->left->data){
        root->left=lr(root->left);
        return rr(root);

    }//rl
    else if(bal<-1 && val<root->right->data){
        root->right=rr(root->right);
        return lr(root);
    }
    return root;
}

void inorder(struct avl* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d", root->data);
        inorder(root->right);
    }
}
int main(){
    struct avl* root = NULL;
    int key;

    printf("AVL TREE PROGRAM\n");
    printf("Enter keys to insert into the AVL tree (Enter -1 to stop):\n");

    while (1) {
        scanf("%d", &key);
        if (key == -1) {
            break;
        }
        root = insert(root, key);
    }

    printf("In-order traversal of the AVL tree: ");
    inorder(root);
    printf("\n");

    return 0;
}
