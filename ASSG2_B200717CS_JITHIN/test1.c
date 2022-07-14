#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct s{
    char ch[100];
    struct s* nxt;
};
void insert(struct s *arr[],int siz){
    char str[100];
    for(int i=0;i<siz;i++){
        scanf("%s",&str);
        struct s *sel=malloc(siz*sizeof(struct s));
        strcpy(sel->ch,str);
        sel->nxt=NULL;
        arr[i]=sel;
    }
}
void print(struct s *arr[],int siz){
    for(int i=0;i<siz;i++){
        printf("%s\n",arr[i]->ch);
    }
}
int main(){
    struct s **arr;
    int siz;
    scanf("%d",&siz);
    arr=malloc(siz*sizeof(struct s*));
    insert(arr,siz);
    print(arr,siz);

    return 0;
}