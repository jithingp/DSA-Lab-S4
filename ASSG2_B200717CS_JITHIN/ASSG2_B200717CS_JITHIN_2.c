#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct s{
    char *shabd;
    struct s* nxt;
};
int hashfun(char sam[],int siz){
    int len=strlen(sam);
    return (len*len)%siz;
}
void insert(struct s *arr[],char *word,int siz,int index){
    
    struct s *selli=(struct s*)malloc(sizeof(struct s));
    selli->shabd=word;
    selli->nxt=NULL;
    struct s * sel=arr[index];
    if(sel!=NULL){
    while(sel->nxt!=NULL){
        sel=sel->nxt;
    }
    sel->nxt=selli;
    return;
    }
    arr[index]=selli;

}
void print(struct s *arr[],int siz){
    for(int i=0;i<siz;i++){
        printf("%d:",i);
        struct s *sel=arr[i];
        if(sel==NULL){
            printf("null");
        }
        int j=0;
        while(sel!=NULL){
            if(j==0){
            printf("%s",sel->shabd);
            j=1;
            }
            else{
                printf("-%s",sel->shabd);
            }
            sel=sel->nxt;
        }
        printf("\n");
    }
}
int search(struct s *arr[],char *word,int siz,int index){
    struct s *sel=arr[index];
    while(sel!=NULL){
        if(strcmp(sel->shabd,word)==0){
            //printf("well\n");
            return 0;
        }
        sel=sel->nxt;
    }
    return 1;
}
int main(){
    int siz;
    scanf("%d\n",&siz);
    struct s *arr[siz];
    for(int i=0;i<siz;i++){
        arr[i]=NULL;
    }
    char str[1000];
    scanf("%[^\n]s",str);
    //const char s[1]=" ";
    char *word;
    word=strtok(str," ");
    while(word!=NULL){
        //printf("%s ",word);
        int index=hashfun(word,siz);
       if( search(arr,word,siz,index)==1)
        insert(arr,word,siz,index);
       word=strtok(NULL," ");
    }
    print(arr,siz);


    return 0;

}