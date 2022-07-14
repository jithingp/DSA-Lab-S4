#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct s{
    int key;
    struct s* left;
    struct s* right;
};
struct s* createnode(int k){
    struct s *node=NULL;
    node=(struct s*)malloc(sizeof(struct s));
    node->key=k;
    node->left=NULL;
    node->right=NULL;
    return node;
}

struct s* insert(struct s* t,struct s* z){
    if(t==NULL)
    return z;

    if(z->key<t->key){
        t->left=insert(t->left,z);
    }
    else{
       t->right= insert(t->right,z);
    }
    
    return t;
}
int treeheight(struct s* t){
    if(t==NULL){
        return 0;
    }
    int m1=treeheight(t->left);
    int m2=treeheight(t->right);
    if(m1>m2)
    return m1+1;

    return m2+1;
}
int isavl(struct s* t){
    if(t==NULL){
        return 1;
    }
    int lefth=treeheight(t->left);
    int righth=treeheight(t->right);
    int b;
    if(lefth>righth)
    b=lefth-righth;
    else
    b=righth-lefth;

    if(b<=1 && isavl(t->left) && isavl(t->right)){
        return 1;
    }
    return 0;
}
int main(){
    struct s* troot=NULL,*z=NULL,*s=NULL;
    char ch;
    int k,m;
    do{
        scanf("%c",&ch);
        switch(ch){
            case 'i':
            scanf("%d",&k);
            z=createnode(k);
            troot=insert(troot,z);
            break;
            case 'c':
            m=isavl(troot);
            printf("%d\n",m);
            break;
        }

    }while(ch!='t');

    return 0;
}
