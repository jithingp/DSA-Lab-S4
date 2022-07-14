#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct s{
    int key;
    struct s* left;
    struct s* right;
    char color;
};
struct t{
    struct s* root;
};
int retnum(char strnum[],int strlen){
    int tot=0,flag=0,j=0;
        if(strnum[0]=='-'){
            j++;
            flag=1;
        }
        for(int i=j;i<strlen;i++){
            int num1=strnum[i]-'0';
            tot=(tot*10)+num1;
        }
        if(flag==1)
        tot=-1*tot;
        return tot;
}
struct s* createnode(int num){
    struct s* z=NULL;
    z=(struct s*)malloc(sizeof(struct s));
    z->color='R';
    z->key=num;
    z->left=NULL;
    z->right=NULL;
    return z;
}
struct s* rotateleft(struct s* t){
    struct s* tright=t->right;
    struct s* trleft=tright->left;

    tright->left=t;
    t->right=trleft;

    return tright;
}
struct s* rotateright(struct s* t){
    struct s* tleft=t->left;
    struct s* tlright=tleft->right;

    tleft->right=t;
    t->left=tlright;

    return tleft;
}
struct s* insert(struct s* node,struct s* z){
    if(node==NULL)
    return z;
    else if(z->key<node->key){
        node->left=insert(node->left,z);
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
void print(struct s* node){
    if(node==NULL){
        printf("( ) ");
        return;
    }
 
    printf("( ");
    printf("%d ",node->key);
    printf("%c ",node->color);
    print(node->left);
    print(node->right);
    printf(") ");
}
int main(){
    struct t* tree=NULL;
    tree=(struct t*)malloc(sizeof(struct t));
    tree->root=NULL;
    char strnum[5];
    while(1){
        scanf("%s",&strnum);
        if(strnum[0]=='t'){
            break;
        }
        int len=strlen(strnum);
        int num=retnum(strnum,len);
        struct s* z=createnode(num);
        tree=redblack(tree,z);
        print(tree->root);
        printf("\n");
    }


    return 0;
}