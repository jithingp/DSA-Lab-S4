#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct s{
    int key;
    char eid[4];
    struct s* left;
    struct s* right;
    struct s* parent;
};
struct ll{
    struct s* qq;
};
struct s* newnode(int rto,char sr[]){
    struct s* node=NULL;
    node=(struct s*)malloc(sizeof(struct s));
    node->key=rto;
    strcpy(node->eid,sr);
    node->left=NULL;
    node->right=NULL;
    node->parent=NULL;
    return node;
}
int findind(char ch[],int j,int n,int ar[]){
    if(n<j)
        return -1;
    int z=0,stage=1,tot=0,flag=0,supreme;
    for(int i=j;i<n;i++){
        if(ch[i]=='('){
            z++;
            if(ch[i+2]!=')'){
                i=i+6;
            }
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
                if(stage==1)
                ar[0]++;
                else if(stage==2)
                ar[1]++;
               
            }
            tot=0;
        }
        if(z==0&&stage==1){
        supreme= i+1;
        stage=2;
        }
    }
    if(ar[0]==0&&ar[1]==0){
        return -1;
    }
    else {
        return supreme;
    }
    return -1;

}
struct s* riker(char ch[],int j,int n){
    if(j>n)
        return NULL;
    int flag=0,rto=0;
    char sr[4];
    strncpy(sr,ch+j,4);
    j=j+5;
    if(ch[j]=='-'){
        flag=1;
        j++;
    }
    while(ch[j]!=' '){
        int num=ch[j]-'0';
        rto=(rto*10)+num;
        j++;
    }    
    if(flag==1){
        rto=-1*rto;
    }
    int ar[2];
    ar[0]=0;
    ar[1]=0;
    struct s* root=newnode(rto,sr);
    int index=-1;
    if(j<=n&&ch[j+1]=='(')
        index=findind(ch,j+1,n,ar);

    if(index!=-1){
        if(ar[0]!=0){
        root->left=riker(ch,j+3,index-1);
        root->left->parent=root;
        }
        if(ar[1]!=0){
        root->right=riker(ch,index+3,n-2);
        root->right->parent=root;
        }
    }  
    return root;  
}
void inorder(struct s* node){
    if(node!=NULL){
        return;
    }
    inorder(node->left);
    printf("%s ",node->eid);
    inorder(node->right);
}
int main(){
    char ch[100000];
    //struct ll *root=NULL;
    fgets(ch,100000,stdin);
    int n=strlen(ch);
    //scanf("%d%d",&num,&dist);
    struct s* root=riker(ch,2,n-2);
    
    inorder(root);
    //printf("%d\n",ele->key);
    
    
    return 0;

}
