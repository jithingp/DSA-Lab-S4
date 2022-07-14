#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
struct s* csum(struct s* ele,int dist,int ennam[]){
    if(ele==NULL)
    return NULL;
    if(dist==ennam[1]&&ele->color=='B')
    return ele;
    dist++;
    struct s* v1=csum(ele->left,dist,ennam);
    if(v1!=NULL)
    return v1;
    return csum(ele->right,dist,ennam);
}
struct s* psum(struct s* ele,int dist,int ennam[],int dia){
    while(dist<=ennam[1]&&ele!=NULL){
        if(dist==ennam[1]&&ele->color=='B')
        return ele;
        if(dia==1){
        struct s* ret=csum(ele->right,dist+1,ennam);
        if(ret!=NULL)
        return ret;
        }
        else{
        struct s* ret=csum(ele->left,dist+1,ennam);
        if(ret!=NULL)
        return ret;
        }
        if(ele->parent!=NULL){
        if(ele==ele->parent->left)
        dia=1;
        else
        dia=2;
        }
        ele=ele->parent;
        dist++;
    }
    return NULL;
}
void traverse(struct s* node,int ennam[]){
    if(node==NULL){
        return;
    }
    struct s* k=csum(node,0,ennam);
    if(k!=NULL){
        ennam[0]++;
        //printf("%d ",node->key);
        //printf("%d\n",k->key);
    }
    else{
        int dia;
        if(node->parent!=NULL){
            if(node==node->parent->left)
            dia=1;
            else
            dia=2;
        }
        struct s* psumret=psum(node->parent,1,ennam,dia);
        if(psumret!=NULL){
        ennam[0]++;
        //printf("%d ",node->key);
        //printf("%d\n",psumret->key);
        }
    }

    traverse(node->left,ennam);
    traverse(node->right,ennam);
   
}
int main(){
    struct t* tree=NULL;
    tree=(struct t*)malloc(sizeof(struct t));
    tree->root=NULL;
    int bdist,totelements,num;
    int ennam[2];
    scanf("%d",&bdist);
    ennam[0]=0;
    ennam[1]=bdist;
    scanf("%d",&totelements);
    for(int i=0;i<totelements;i++){
        scanf("%d",&num);
        struct s* z=createnode(num);
        tree=redblack(tree,z);
    }
    traverse(tree->root,ennam);
    printf("%d",ennam[0]);
   
    return 0;
}