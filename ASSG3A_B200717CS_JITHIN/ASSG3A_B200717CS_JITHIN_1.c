#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct s{
    int key;
    int height;
    struct s* left;
    struct s* right;
    struct s* parent;
};
struct s* createnode(int k){
    struct s *node=NULL;
    node=(struct s*)malloc(sizeof(struct s));
    node->key=k;
    node->height=1;
    node->left=NULL;
    node->parent=NULL;
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
    if(z->key==t->key)
    return t;
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
struct s* search(struct s* node,int k){
    if(node==NULL||k==node->key)
    return node;
    if(k<node->key)
    return search(node->left,k);
    else
    return search(node->right,k);
}
void getbalance(struct s* t,int key){
    struct s* rr=search(t,key);
    if(rr==NULL){
        printf("%s\n","FALSE");
        return;
    }
    int heightleft=(rr->left)?rr->left->height:0;
    int heightright=(rr->right)?rr->right->height:0;

    printf("%d\n",heightleft-heightright);
}
void print(struct s* node){
    if(node==NULL){
        printf("( ) ");
        return;
    }
 
    printf("( ");
    printf("%d ",node->key);
    print(node->left);
    print(node->right);
    printf(") ");
}
struct s* inorderpred(struct s* t){
    struct s* node=t;
    while(node->right!=NULL){
        node=node->right;
    }
    return node;
}
struct s* delete(struct s* t,int ele){
    if(t==NULL)
    return t;

    if(ele < t->key){
        t->left=delete(t->left,ele);
    }
    else if(ele > t->key){
        t->right=delete(t->right,ele);
    }
    else{
        if(t->left==NULL){
            struct s* kraken=t->right;
            free(t);
            return kraken;
        }
        else if(t->right==NULL){
            struct s* kraken=t->left;
            free(t);
            return kraken;
        }
        struct s* kraken=inorderpred(t->left);
        t->key=kraken->key;
        t->left=delete(t->left,kraken->key);

    }
    if(t==NULL){
        return t;
    }
    t->height=calcheight(t);

    int bb=balancecalc(t);

    if(bb>1 && balancecalc(t->left)>=0){
        return rotateright(t,t->key);
    }
    else if(bb>1 && balancecalc(t->left)<0){
        t->left=rotateleft(t->left,t->left->key);
        return rotateright(t,t->key);
    }
    else if(bb<-1 && balancecalc(t->right)<=0){
        return rotateleft(t,t->key);
    }
    else if(bb<-1 && balancecalc(t->right)>0){
        t->right=rotateright(t->right,t->right->key);
        return rotateleft(t,t->key);
    }
    return t;
}
int main(){
    struct s* troot=NULL,*z=NULL,*s=NULL;
    char ch;
    int k;
    do{
        scanf("%c",&ch);
        switch(ch){
            case 'i':
            scanf("%d",&k);
            z=createnode(k);
            troot=insert(troot,z);
            break;
            case 'p':
            print(troot);
            printf("\n");
            break;
            case 's':
            scanf("%d",&k);
            s=search(troot,k);
            if(s==NULL)
            printf("%s\n","FALSE");
            else
            printf("%s\n","TRUE");
            break;
            case 'b':
            scanf("%d",&k);
            getbalance(troot,k);
            break;
            case 'd':
            scanf("%d",&k);
            s=search(troot,k);
            if(s==NULL)
            printf("%s\n","FALSE");
            else
            {
            printf("%d\n",k);    
            troot=delete(troot,k);
            }
            break;
    }

    }while(ch!='e');

return 0;
}