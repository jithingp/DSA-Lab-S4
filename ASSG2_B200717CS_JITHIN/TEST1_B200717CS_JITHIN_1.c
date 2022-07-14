#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct s{
    char *shabd;
    struct s* nxt;
};
int hashfun1(char sam[],int siz){
    int len=strlen(sam),index=0;
    if(len==1){
        index=(2*sam[0])%siz;
    }
    else{
        int rr;
        int k=(sam[0]+sam[1]+sam[len-2]+sam[len-1])%len;
        if(k>0){
            rr=((sam[0]+sam[1]+sam[len-2]+sam[len-1])/len)+1;
        }
        else{
             rr=((sam[0]+sam[1]+sam[len-2]+sam[len-1])/len);
        }
        index=(rr)%siz;
    }
    return index;

}
int hashfun2(char sam[],int siz){
    int len=strlen(sam),index=0;
    for(int i=0;i<len;i++){
        index=index+sam[i];
    }
    index=(index/len)%siz;
    return index;
}
void insert(struct s *arr[],char *word,int siz){
    int index1=hashfun1(word,siz);
    int index2=hashfun2(word,siz);
    int index=0;
    int count1=0,count2=0;
    struct s* mell=arr[index1];
    struct s* melli=arr[index2];
    while(mell!=NULL){
        mell=mell->nxt;
        count1++;
    }
    while(melli!=NULL){
        melli=melli->nxt;
        count2++;
    }
    if(count1<=count2){
        index=index1;
    }
    else{
        index=index2;
    }
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
        //printf("%d:",i);
        struct s *sel=arr[i];
        if(sel==NULL){
            printf("NULL");
        }
        int j=0;
        while(sel!=NULL){
            if(j==0){
            printf("%s",sel->shabd);
            j=1;
            }
            else{
                printf(" %s",sel->shabd);
            }
            sel=sel->nxt;
        }
        printf("\n");
    }
}

int main(){
    int siz;
    scanf("%d\n",&siz);
    struct s *arr[siz];
    for(int i=0;i<siz;i++){
        arr[i]=NULL;
    }
    char str[100000];
    scanf("%[^\n]s",str);
    //const char s[1]=" ";
    char *word;
    word=strtok(str," ");
    while(word!=NULL){
        //printf("%s ",word);
        
      
        insert(arr,word,siz);
       word=strtok(NULL," ");
    }
    print(arr,siz);


    return 0;

}