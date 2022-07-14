#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
void count(char ch[],int n,int root,int j){
    int z=0,crak=0,stage=1,tot=0,flag=0;
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
                if(stage==1){
                    if(tot>root){
                        crak=1;
                        stage=3;
                    }
                }
                else if(stage==2){
                    if(tot<root){
                        crak++;
                        stage=3;
                    }
                }
            }
            tot=0;
        }
        if(z==0)
        stage=2;
    }
    printf("%d",crak);

}
int main(){
    char ch[100000];
    fgets(ch,100000,stdin);
    int n=strlen(ch);
    int root=0,j=2,flag=0;
    if(ch[j]=='-'){
        flag=1;
        j++;
    }
    while(ch[j]!=' '){
        int num=ch[j]-'0';
        root=(root*10)+num;
        j++;
    }
    if(flag==1){
        root=-1*root;
    }
    count(ch,n,root,j);

    return 0;
}