#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int count(char ch[],int n,int root,int j,int ar[]){
    if(n<=2){
        return -1;
    }
    int ennam=1,root1,root2,r1=0,r2=0,kk=2,manu,vinu;
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
            kk++;
        }
        else if(isdigit(ch[i])){
            int k=ch[i]-'0';
            tot=tot*10 + k;
            kk++;
        }

        else if(ch[i]==' '){
            if(isdigit(ch[i-1])){
                ennam++;
                if(flag==1){
                tot=-1*tot;
                flag=0;
            }
                if(stage==1){
                    if(ennam==2){
                        root1=tot;
                        r1=1;
                        manu=kk;
                    }
                    if(tot>root){
                        crak=1;
                        //stage=3;
                    }
                }
                else if(stage==2){
                    if(r2==0){
                        root2=tot;
                        r2=1;
                        vinu=kk;
                    }
                    if(tot<root){
                        crak++;
                        //stage=3;
                    }
                }
            }
            tot=0;
            kk=2;
        }
        if(z==0&&stage==1){
            ar[0]=j+1;
            ar[1]=i+1;
        stage=2;
        }
    }
    int ar1[2],ar2[2];
    if(crak>0){
        return 0;
    }
    if(crak==0){
        if(ennam>3){
             int m=ar[1]-ar[0],mm=n-(ar[1]+1),w1,w2;
            char zz[100000],zz1[100000];
            strncpy(zz,ch+ar[0],m);
            strncpy(zz1,ch+ar[1]+1,mm);
            if(r1==1){
                w1=count(zz,m,root1,manu,ar1);
            }
            if(r2==1){
                w2=count(zz1,mm,root2,vinu,ar2);
            }
            if(w1==0||w2==0){
                return 0;
            }
        }
        return ennam;
    }
    return 0;

}
int riker(char ch[],int n){
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
    int ennam=count(ch,n,root,j,ar);
    if(ennam>=1||ennam<0){
        return ennam;
    }

    int m=ar[1]-ar[0],mm=n-(ar[1]+1);
    char zz[100000],zz1[100000];
    strncpy(zz,ch+ar[0],m);
    strncpy(zz1,ch+ar[1]+1,mm);
    int num1=riker(zz,m);
    int num2=riker(zz1,mm);
    if(num1>num2)
    return num1;
    return num2;
    
}
int main(){
    char ch[100000];
    fgets(ch,100000,stdin);
    int n=strlen(ch);
    n--;
    int siz=riker(ch,n);
    printf("%d",siz);

    return 0;
}