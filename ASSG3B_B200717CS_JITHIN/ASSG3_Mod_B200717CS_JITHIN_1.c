#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct s{
    int key;
    struct s* parent;
    struct s* left;
    struct s* right;
    char color;
};
struct t{
    struct s* root;
};
struct s* createnode(int num){
    struct s* z=NULL;
    z=(struct s*)malloc(sizeof(struct s));
    z->color='R';
    z->key=num;
    z->left=NULL;
    z->right=NULL;
    z->parent=NULL;
    return z;
}
struct s* rotateleft(struct s* t){
    struct s* tright=t->right;
    struct s* trleft=tright->left;
    
    tright->parent=t->parent;
    tright->left=t;
    t->parent=tright;
    t->right=trleft;
    if(trleft!=NULL)
    trleft->parent=t;

    return tright;
}
struct s* rotateright(struct s* t){
    struct s* tleft=t->left;
    struct s* tlright=tleft->right;

    tleft->parent=t->parent;
    tleft->right=t;
    t->parent=tleft;
    t->left=tlright;
    if(tlright!=NULL)
    tlright->parent=t;

    return tleft;
}
struct s* insert(struct s* node,struct s* z){
    if(node==NULL)
    return z;
    else if(z->key<node->key){
        node->left=insert(node->left,z);
        node->left->parent=node;
        if(node->left->color=='B')
            return node;
        else{
            if(node->left->left!=NULL){
            if(node->left->left->color=='R'){
                
                if(node->right==NULL||node->right->color=='B'){
                    if(node->left->right!=NULL)
                    if(node->left->right->color=='R'){
                        node->left=rotateleft(node->left);
                    }
                    struct s* y=rotateright(node);
                    y->right->color='R';
                    y->color='B';
                    return y;
                }
                else{
                    node->right->color='B';
                    node->left->color='B';
                    node->color='R';
                    return node;
                }
            }
           
            }
            if(node->left->right!=NULL){
            if(node->left->right->color=='R'){
                
                if(node->right==NULL||node->right->color=='B'){
                    if(node->left->right!=NULL)
                    if(node->left->right->color=='R'){
                        node->left=rotateleft(node->left);
                    }
                    struct s* y=rotateright(node);
                    y->right->color='R';
                    y->color='B';
                    return y;
                }
                else{
                    node->right->color='B';
                    node->left->color='B';
                    node->color='R';
                    return node;
                }
            }
           
            }
        }
        return node;    
    }
    else{
        node->right=insert(node->right,z);
        node->right->parent=node;
        if(node->right->color=='B'){
            return node;
        }
        else{
            if(node->right->right!=NULL){
                if(node->right->right->color=='R'){
                    
                    if(node->left==NULL||node->left->color=='B'){
                        if(node->right->left!=NULL)
                        if(node->right->left->color=='R'){
                            node->right=rotateright(node->right);
                        }
                        struct s* y=rotateleft(node);
                        y->left->color='R';
                        y->color='B';
                        return y;
                    }
                    else{
                        node->left->color='B';
                        node->right->color='B';
                        node->color='R';
                        return node;
                    }
                }
            }
            if(node->right->left!=NULL){
                if(node->right->left->color=='R'){
                    
                    if(node->left==NULL||node->left->color=='B'){
                        if(node->right->left!=NULL)
                        if(node->right->left->color=='R'){
                            node->right=rotateright(node->right);
                        }
                        struct s* y=rotateleft(node);
                        y->left->color='R';
                        y->color='B';
                        return y;
                    }
                    else{
                        node->left->color='B';
                        node->right->color='B';
                        node->color='R';
                        return node;
                    }
                }
            }
        }
        return node;
    }
}
struct t* redblack(struct t* tree,struct s* z){
    tree->root=insert(tree->root,z);
    if(tree->root->color=='R')
    tree->root->color='B';
    return tree;
}
int checkbeautiful(struct s* rt){
    if(rt==NULL)
        return 1;
    char ch=rt->color;
    char ch1=ch;
    char ch2=ch;
    char ch3=ch;
    char ch4=ch;
    if(rt->left!=NULL){
        if(rt->left->left!=NULL)
        ch1=rt->left->left->color;
        if(rt->left->right!=NULL)
        ch2=rt->left->right->color;
    }
    if(rt->right!=NULL){
        if(rt->right->left!=NULL)
        ch3=rt->right->left->color;
        if(rt->right->right!=NULL)
        ch4=rt->right->right->color;
    }
    if(ch!=ch1||ch!=ch2||ch!=ch3||ch!=ch4){
        return -1;
    }
    int m1=checkbeautiful(rt->left);
    int m2=checkbeautiful(rt->right);
    if(m1==-1||m2==-1){
        return -1;
    }
    return 1;

}
int main(){
    struct t* tree=NULL;
    tree=(struct t*)malloc(sizeof(struct t));
    tree->root=NULL;
    int totelements,num;
    scanf("%d",&totelements);
    for(int i=0;i<totelements;i++){
        scanf("%d",&num);
        struct s* z=createnode(num);
        tree=redblack(tree,z);
    }
    int m=checkbeautiful(tree->root);
    printf("%d",m);
    return 0;
}