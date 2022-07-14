#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int count(char ch[],int n,int root,int j,int num1,int num2,int ar[]){
    int z=0,crak=0,stage=1,tot=0;
    int flag=0;
    for(int i=j+1;i<n;i++){
        if(ch[i]=='('){
            z++;
        }
        else if(ch[i]==')'){
            z--;
        }
        else if(ch[i]=='-'){
            flag=1;
         }
        else if(isdigit(ch[i])){
            int k=ch[i]-'0';
            tot=tot*10 + k;
        }
        else if(ch[i]==' '){
            if(isdigit(ch[i-1])){
                if(flag==1){
                    tot=-1*tot;
                    flag=0;
                }
                if(tot==num1||tot==num2){
                        crak++;
                    }
                 }
                tot=0;
            }
            
        
        if(z==0&&stage==1){
            if(crak==2){
                ar[0]=j+1;
                ar[1]=i+1;
                return 1;
            }
            else if(crak==1){
                return -1;
            }
            else if(crak==0){
                ar[0]=i+2;
                ar[1]=n-1;
                return 1;
            }
        }
    }

    return 1;

}
int riker(char ch[],int n,int num1,int num2){
    int flag=0,j=2,ar[2];
    if(ch[j]=='-'){
        flag=1;
        j++;
    }
     int root=0;
    while(ch[j]!=' '){
        int num=ch[j]-'0';
        root=(root*10)+num;
        j++;
    }
    ar[0]=0;
    ar[1]=n;
    if(flag==1){
        root=-1*root;
    }
    if(root==num1||root==num2){
        return root;
    }
    //printf("%d",root);
    int top=count(ch,n,root,j,num1,num2,ar);
    if(top==-1){
        return root;
    }
    else{
        int m=ar[1]-ar[0];
        char zz[100000];
        strncpy(zz,ch+ar[0],m);
        return riker(zz,m,num1,num2);
    }
}
int main(){
    char ch[100000];
    int num1,num2;
    fgets(ch,100000,stdin);
    scanf("%d%d",&num1,&num2);
    int n=strlen(ch);
    int lca=riker(ch,n-1,num1,num2);
    printf("%d",lca);

    return 0;
}