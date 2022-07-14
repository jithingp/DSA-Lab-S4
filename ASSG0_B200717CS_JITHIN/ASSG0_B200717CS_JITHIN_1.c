#include<stdio.h>
#include<stdlib.h>
struct s{
    int top;
    int *e;
};
int isfull(struct s* ar,int *size){
    if(ar->top<(*size)-1){
        return -1;
    }
    (*size)*=2;
    int *b=(int*)malloc(*size*sizeof(int));
    for(int i=0;i<(*size)/2;i++){
        b[i]=ar->e[i];
    }
    free(ar->e);
    ar->e=b;
    //free(z);
    return 1;
}
void push(struct s *ar,int *size){
    int k;
    scanf("%d",&k);
    if(isfull(ar,size)==1){
        printf("%d\n",1);
    }
    ar->top++;
  
    ar->e[ar->top]=k;
 }
 int isempty(struct s* ar){
     if(ar->top==-1){
         return -1;
     }
     return 1;
 }
void pop(struct s* ar,int *size){
    if(isempty(ar)==-1){
        printf("%d\n",-1);
        return;
    }
    printf("%d\n",ar->e[ar->top]);
    ar->top--;

}
int main(){
    struct s *ar=NULL;
    ar=(struct s*)malloc(sizeof(struct s));
    ar->top=-1;
    int size;
   
    scanf("%d",&size);
    ar->e=NULL;
    ar->e =(int*)malloc(size*sizeof(int));
    char ch;
    do
    {
        scanf("%c",&ch);
        switch(ch){
            case 'i':
            push(ar,&size);
            break;
            case 'd':
            pop(ar,&size);
            break;

        }

    } while (ch!='t');
    

    return 0;
}