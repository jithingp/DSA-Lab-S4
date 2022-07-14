#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct s{
    char *rev;
};
int hashfun(char name[]){
    int n1=0,n2=0,n3=0,i=0,j=0,k=0;
    int len=strlen(name);
    while(i<len&&i<3){
        n1=n1+name[i];
        i++;
    }
    while(j<len&&j<5){
        n2=n2+name[j];
        j+=2;
    }
    while(k<len&&k<9){
        n3=n3+name[k];
        k+=4;
    }
    n1=(n1%26)%10;
    n2=(n2%26)%10;
    n3=(n3%26)%10;
    int m=(100*n1)+(10*n2)+(n3);
    return m;
}
void insertdata(char *riker,struct s *arr[]){
    struct s* sel=(struct s*)malloc(sizeof(struct s));
    int index=hashfun(riker);
    sel->rev=riker;
    arr[index]=sel;
}
void search(char *rollno,struct s *arr[]){
    int n1=rollno[1]-'0';
    int n2=rollno[2]-'0';
    int n3=rollno[3]-'0';
    int m=(100*n1)+(10*n2)+n3;
    struct s* sel=arr[m];
    if(arr[m]==NULL){
        printf("%s\n","NOT FOUND");
        return;
    }
    
     printf("%s\n",sel->rev);
}
void delete(char *rollno,struct s *arr[]){
    int n1=rollno[1]-'0';

    int n2=rollno[2]-'0';
    int n3=rollno[3]-'0';
    int m=(100*n1)+(10*n2)+n3;
    arr[m]=NULL;
}
int main(){
    char ch,*riker=NULL,*rollno=NULL;
    struct s* arr[1000];
    for(int i=0;i<1000;i++){
        arr[i]=NULL;
    }
    do{
        scanf("%c",&ch);
        switch(ch){
            case 'i':
            riker=(char*)malloc(1000*sizeof(char));
            scanf(" %s\n",riker);
            insertdata(riker,arr);
            break;
            case 's':
            rollno=(char*)malloc(4*sizeof(char));
            scanf(" %s\n",rollno);
            search(rollno,arr);
            break;
            case 'd':
            rollno=(char*)malloc(4*sizeof(char));
            scanf(" %s\n",rollno);
            delete(rollno,arr);
            break;
        }

    }while(ch!='t');
    return 0;
}