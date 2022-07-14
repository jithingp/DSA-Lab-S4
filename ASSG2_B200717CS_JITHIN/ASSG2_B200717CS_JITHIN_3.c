#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct s{
    char firstname[100000];
    char secname[100000];
    int key;
    struct s* p;
    struct s* left;
    struct s* right;
};
struct st{
    struct s* bt;
    struct st *nxt;
};
int hashfun(char lname[]){
    int len=strlen(lname);
    int sum=0;
    for(int i=0;i<len;i++){
        sum+=lname[i];
    }
    return sum;
}
struct s* createnode(char fname[],char lname[],int age){
    struct s* ele=(struct s*)malloc(sizeof(struct s));
    strcpy(ele->firstname,fname);
    strcpy(ele->secname,lname);
    ele->key=age;
    ele->p=NULL;
    ele->left=NULL;
    ele->right=NULL;
    return ele;
}
void insert(struct s* arr[],char fname[],char lname[],int age){
    int index=hashfun(lname);
    struct s* z=createnode(fname,lname,age);
    struct s *y=NULL;
    struct s *x=arr[index];
    while(x!=NULL){
        y=x;
        if(z->key<x->key){
            x=x->left;
        }
        else{
            x=x->right;
        }
    }
    z->p=y;
    if(y==NULL)
    arr[index]=z;
    else if(z->key<y->key)
    y->left=z;
    else
    y->right=z;
}
struct s* preorder(struct s* node,char fname[],char lname[]){
    if(node==NULL)
    return NULL;
    if(strcmp(node->firstname,fname)==0&&strcmp(node->secname,lname)==0){
        return node;
    }
    struct s* v1=preorder(node->left,fname,lname);
    if(v1!=NULL)
    return v1;
    return preorder(node->right,fname,lname);
}
void printrelatives(char fname[],char lname[],struct s* arr[]){
    int index=hashfun(lname);
    struct s* node=arr[index];
    struct s* q=preorder(node,fname,lname);
    if(q==NULL){
        printf("%d\n",-1);
        return;
    }
    struct st* tri=NULL;
    while(q!=NULL){
        struct st* new=(struct st*)malloc(sizeof(struct st));
        new->nxt=tri;
        new->bt=q;
        tri=new;
        q=q->p;
    }
    while(tri!=NULL){
        printf("%s ",tri->bt->firstname);
        printf("%s ",tri->bt->secname);
        printf("%d\n",tri->bt->key);
        tri=tri->nxt;
    }
    

}
int main(){
    char ch;
    char fname[100000],lname[100000];
    struct s* arr[128];
    int age;
    do{
        scanf("%c",&ch);
        switch(ch){
            case 'i':
            scanf(" %s ",&fname);
            scanf(" %s ",&lname);
            scanf("%d",&age);
            insert(arr,fname,lname,age);
            break;
            case 'p':
            scanf(" %s ",&fname);
            scanf(" %s ",&lname);
            printrelatives(fname,lname,arr);
            break;
        }
    }while(ch!='t');


    return 0;
}