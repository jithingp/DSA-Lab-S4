#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int count(char ch[],int n,int root,int j,int num1,int num2,int ar[]){
    int z=0,crak=0,stage=1,tot=0,cc=0;
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
                cc++;
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
            
                ar[0]=j+1;
                ar[1]=i+1;
       }
    }
    return cc;

}
void riker(char ch[],int n,int num1,int num2,int vin[]){
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
    if(vin[2]==1){
        vin[0]=vin[0]+root;
        vin[1]--;
    }
    if(root==num1){
        vin[2]=1;
        vin[0]=vin[0]+root;
    }
    
    //printf("%d",root);
    int cc=count(ch,n,root,j,num1,num2,ar);
    if(cc<2){
        return;
    }
    if(vin[1]==0){
        vin[2]=0;
        return;
    }
    else{
        int m=ar[1]-ar[0],mm=n-ar[1]-2;
        char zz[100000],zzz[100000];
        strncpy(zz,ch+ar[0],m);
        strncpy(zzz,ch+ar[1]+1,mm);
        int er=vin[1];
        riker(zz,m,num1,num2,vin);
        vin[1]=er;
        vin[0]=1;
        riker(zzz,mm,num1,num2,vin);
        if(root==num1){
            vin[1]=num2;
            vin[0]=1;
        }
        else if(vin[0]==1){
            vin[2]+=root;
            vin[1]--;
            if(vin[1]==0){
                vin[0]=0;
            }
        }
    }
}
int main(){
    char ch[100000];
    int num1,num2;
    int vin[3];

    fgets(ch,100000,stdin);
    scanf("%d%d",&num1,&num2);
    int n=strlen(ch);
    vin[0]=0;
    vin[1]=num2;
    vin[2]=0;
    riker(ch,n-1,num1,num2,vin);
    printf("%d",vin[0]);

    return 0;
}