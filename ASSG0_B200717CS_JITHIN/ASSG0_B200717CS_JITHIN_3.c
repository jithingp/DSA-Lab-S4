#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct s{
    int val;
    struct s* nxt;
};
struct ll{
    struct s *head;
};
struct s* createnode(int k){
    struct s* dex=(struct s*)malloc(sizeof(struct s));
    dex->val=k;
    dex->nxt=NULL;
    return dex;
}
int main(){
    struct s *p=NULL;
    p=(struct s*)malloc(sizeof(struct s));
    p=NULL;
    struct ll *a=NULL;
    a=(struct ll*)malloc(sizeof(struct ll));
    a->head=NULL;
    char ch;
    int num,x,j=0,tot=0;
    char str[100000];
    fgets(str,100000,stdin);
    int siz=strlen(str);
    for(int i=0;i<siz;i++){
        ch=str[i];
        if(ch!=' '&&ch!='\n'){   
        num=ch-'0';
        tot=(tot*10)+num;
       }
        else{
            struct s* q=createnode(tot);
            tot=0;
            if(j==0){
            a->head=q;
            }
            if(p!=NULL){
                p->nxt=q;
            }
            p=q;
            j++;
        }
     }
     scanf("%d",&x);
     struct s* sel=a->head;
     if(x<=j){
     for(int i=0;i<j-x;i++){
         sel=sel->nxt;
     }
     printf("%d",sel->val);
     }
     else{
         printf("%d",-1);
     }

    return 0;
}