#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct s{
    int key;
    int height;
    int count;
    struct s* left;
    struct s* right;
};
struct s* createnode(int k){
    struct s *node=NULL;
    node=(struct s*)malloc(sizeof(struct s));
    node->key=k;
    node->height=1;
    node->count=1;
    node->left=NULL;
    node->right=NULL;
    return node;
}
int calcheight(struct s* t){
    int heightleft,heightright;
    heightleft=(t&&t->left)?t->left->height:0;
    heightright=(t&&t->right)?t->right->height:0;

    int h=(heightleft>heightright)?heightleft+1:heightright+1;
    return h;
}
int balancecalc(struct s* t){
    int heightleft=(t&&t->left)?t->left->height:0;
    int heightright=(t&&t->right)?t->right->height:0;

    return heightleft-heightright;
}
struct s* rotateleft(struct s* t,int key){
    struct s* tright=t->right;
    struct s* trleft=tright->left;

    tright->left=t;
    t->right=trleft;

    t->height=calcheight(t);
    tright->height=calcheight(tright);

    return tright;
}
struct s* rotateright(struct s* t,int key){
    struct s* tleft=t->left;
    struct s* tlright=tleft->right;

    tleft->right=t;
    t->left=tlright;

    t->height=calcheight(t);
    tleft->height=calcheight(tleft);

    return tleft;
}
struct s* insert(struct s* t,struct s* z){
    if(t==NULL)
    return z;
    if(z->key==t->key){
        t->count++;
        return t;
    }
    if(z->key<t->key){
        t->left=insert(t->left,z);
    }
    else{
       t->right= insert(t->right,z);
    }
    t->height=calcheight(t);
    if(balancecalc(t)>1 && balancecalc(t->left)==1){
        return rotateright(t,t->key);
    }
    else if(balancecalc(t)>1 && balancecalc(t->left)==-1){
        t->left=rotateleft(t->left,t->left->key);
        return rotateright(t,t->key);
    }
    else if(balancecalc(t)<-1 && balancecalc(t->right)==-1){
        return rotateleft(t,t->key);
    }
    else if(balancecalc(t)<-1 && balancecalc(t->right)==1){
        t->right=rotateright(t->right,t->right->key);
        return rotateleft(t,t->key);
    }
    return t;

}
void print(struct s* node){
    if(node==NULL){
        return;
    }
    print(node->left);
    for(int i=node->count;i>0;i--)
    printf("%d ",node->key);
    print(node->right);
}
int main(){
    struct s* troot=NULL,*z=NULL;
    int siz,ele;
    scanf("%d",&siz);
    for(int i=0;i<siz;i++){
        scanf("%d",&ele);
        z=createnode(ele);
        troot=insert(troot,z);
    }
    print(troot);

    return 0;
}
