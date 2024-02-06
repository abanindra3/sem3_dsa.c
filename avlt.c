#include <stdio.h>
#include <stdlib.h>

struct tree{
    struct tree* right;
    struct tree* left;
    int height;
    int data;
};

struct tree* create(int data){
    struct tree* new=(struct tree*)malloc(sizeof(struct tree));
    new->data=data;
    new->right=NULL;
    new->left=NULL;
    new->height=1;
    return new;
}

int getht(struct tree* root){
    if (root==NULL){
        return 0;
    }
    return root->height;
}

int max(int a,int b){
    return (a>b)?a:b;
}

int bf(struct tree* root){
    if(root==NULL){ return 0;
    }
    return getht(root->left)-getht(root->right);
}

struct tree* lr(struct tree* x){
    struct tree* y=x->right;
    struct tree* t2=y->left;

    y->left=x;
    x->right=t2;

    y->height = max(getht(y->left), getht(y->right)) + 1;
    x->height = max(getht(x->left), getht(x->right)) + 1;
    return y;
}
struct tree* rr(struct tree* y){
    struct tree* x=y->left;
    struct tree* t2=x->right;

    y->left=t2;
    x->right=y;

    y->height = max(getht(y->left), getht(y->right)) + 1;
    x->height = max(getht(x->left), getht(x->right)) + 1;
    return x;
}

struct tree* insert(struct tree* root,int val){
    if(root==NULL){
        return create(val);
    }
    if(root->data>val){
        root->left=insert(root->left,val);
    }else if(root->data<val){
        root->right=insert(root->right,val);
    }else{
        root->height = 1 + max(getht(root->left), getht(root->right));
        return root;
    }
    //root->height = 1 + max(getht(root->left), getht(root->right));
    int bal=bf(root);
    
    //ll
    if(bal>1 && val<root->left->data){
        return rr(root);
    //rr
    }else if(bal<-1 && val>root->right->data){
        return lr(root);
    //lr
    }else if(bal>1 && val>root->left->data){
        root->left=lr(root->left);
        return rr(root);
    //rl
    }else if(bal<-1 && val<root->right->data){
        root->right=rr(root->right);
        return lr(root);
    }
    return root;
}

void inorder(struct tree* root){
    if (root != NULL) {
        inorder(root->left);
        printf("%d " ,root->data);
        inorder(root->right);
    }
}
int main(){
    struct tree* root = NULL;
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
