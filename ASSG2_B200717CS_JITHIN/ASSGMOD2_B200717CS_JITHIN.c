#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
struct s{
    char shabd[100];
    struct s* nxt;
};
int hash(char *str,int siz){
    int len=strlen(str),index=0,temp=0;
    for(int i=0;i<len;i++){
        if(isupper(str[i])){
            temp=str[i]-64;
        }
        else{
            temp=str[i]-96;
        }
        index=index + (pow(3,i)*temp);
    }
    index=index%siz;
    return index;

}
void insert(struct s *arr[],int siz,char str[]){
    int index=hash(str,siz);
    struct s *selli=(struct s*)malloc(sizeof(struct s));
    strcpy(selli->shabd,str);
    selli->nxt=NULL;
    if(arr[index]==NULL){

        arr[index]=selli;
    }
    else{
        selli->nxt=arr[index];
        arr[index]=selli;
    }
}
void checkit(struct s *arr[],int siz){
    for(int i=0;i<siz;i++){
        if(arr[i]!=NULL){
            if(arr[i]->nxt!=NULL){
                printf("%d\n",-1);
                return;
            }
        }
    }
    printf("%d\n",1);
}
int main(){
    int siz;
    scanf("%d\n",&siz);
    
    struct s *arr[siz];
    //*arr=(struct s*)malloc(siz*sizeof(struct s));
    for(int i=0;i<siz;i++){
        arr[i]=NULL;
    }
    char ch,str[100];
    do{
        scanf("%c",&ch);
        switch(ch){
        case 'i':
        scanf(" %s ",&str);
        insert(arr,siz,str);
        break;
        // case 'd':
        // scanf("%s",&str);
        // delete(arr,siz,str);
        // break;
        case 'p':
        checkit(arr,siz);
        break;

        }


    }while(ch!='t');

    return 0;
}