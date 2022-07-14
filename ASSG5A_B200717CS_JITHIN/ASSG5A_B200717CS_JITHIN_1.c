#include<stdio.h>
#include<stdlib.h>
struct s{
    struct s* parent;
    int data;
    int rank;
};
struct t{
    struct t* parent;
    int data;
};
int counta=0,countb=0,countc=0,countd=0;
struct t* createnodet(int num){
    struct t* node=(struct t*)malloc(sizeof(struct t));
    node->data=num;
    node->parent=node;
    return node;
}
struct s* createnodes(int num){
    struct s* node=(struct s*)malloc(sizeof(struct s));
    node->data=num;
    node->parent=node;
    node->rank=0;
    return node;
}

struct t* findset1(struct t* z){
    struct t* temp=z;
    while(temp!=temp->parent){
       temp=temp->parent;
       counta++;
    }
    counta++;
    return temp->parent;
}
struct s* findset2(struct s* z){
    struct s* temp=z;
    while(temp!=temp->parent){
        temp=temp->parent;
        countb++;
    }
    countb++;
    return temp->parent;
}
struct t* findset3(struct t* z){
        countc++;
    if(z!=z->parent){
        z->parent=findset3(z->parent);
    }
    
    return z->parent;
}
struct s* findset4(struct s* z){
    countd++;
    if(z!=z->parent){
        z->parent=findset4(z->parent);
    }
    return z->parent;
}
void union1(struct t* z1,struct t* z2){
    struct t* z1rep=findset1(z1);
    struct t* z2rep=findset1(z2);
    if(z1rep==z2rep){
        printf("%d ",z1rep->data);
        return;
    }
    z2rep->parent=z1rep;
    printf("%d ",z1rep->data);
}
void union2(struct s* z1,struct s* z2){
    struct s* z1rep=findset2(z1);
    struct s* z2rep=findset2(z2);
    if(z1rep==z2rep){
        printf("%d ",z1rep->data);
        return;
    }
    if(z1rep->rank>=z2rep->rank){
        z2rep->parent=z1rep;
        if(z1rep->rank==z2rep->rank)
            z1rep->rank++;
        printf("%d ",z1rep->data);
    }
    else{
        z1rep->parent=z2rep;
        printf("%d ",z2rep->data);    
    }
}
void union3(struct t* z1,struct t* z2){
    struct t* z1rep=findset3(z1);
    struct t* z2rep=findset3(z2);
    if(z1rep==z2rep){
        printf("%d ",z1rep->data);
        return;
    }
    z2rep->parent=z1rep;
    printf("%d ",z1rep->data);
}
void union4(struct s* z1,struct s* z2){
    struct s* z1rep=findset4(z1);
    struct s* z2rep=findset4(z2);
    if(z1rep==z2rep){
        printf("%d",z1rep->data);
        return;
    }
    if(z1rep->rank>=z2rep->rank){
        z2rep->parent=z1rep;
        if(z1rep->rank==z2rep->rank)
            z1rep->rank++;
        printf("%d ",z1rep->data);
    }
    else{
        z1rep->parent=z2rep;
        printf("%d ",z2rep->data);    
    }
}
int main(){
    char ch;
    int k,m,n;
    //int acount=0,bcount=0,ccount=0,dcount=0;
    struct t* asir[10000],*csir[10000];
    struct s* bsir[10000],*dsir[10000];
    for(int i=0;i<10000;i++){
        asir[i]=NULL;
        bsir[i]=NULL;
        csir[i]=NULL;
        dsir[i]=NULL;
    }
    do{
        scanf("%c",&ch);
        switch(ch){
            case 'm':
            scanf("%d",&k);
            if(asir[k]!=NULL)
                printf("%d\n",-1);
            else{    
            printf("%d\n",k);
            asir[k]=createnodet(k);
            csir[k]=createnodet(k);
            bsir[k]=createnodes(k);
            dsir[k]=createnodes(k);
            }
            break;
            case 'u':
            scanf("%d%d",&m,&n);
            if(asir[m]==NULL || asir[n]==NULL)
                printf("%d %d %d %d\n",-1,-1,-1,-1);
            else{    
            union1(asir[m],asir[n]);
            union2(bsir[m],bsir[n]);
            union3(csir[m],csir[n]);
            union4(dsir[m],dsir[n]);
            printf("\n");
            }
            break;
            case 'f':
            scanf("%d",&k);
            if(asir[k]==NULL)
                printf("%d %d %d %d\n",-1,-1,-1,-1);
            else{    
            struct t* s1=findset1(asir[k]);
            printf("%d ",s1->data);
            struct s* s2=findset2(bsir[k]);
            printf("%d ",s2->data);
            struct t* s3=findset3(csir[k]);
            printf("%d ",s3->data);
            struct s* s4=findset4(dsir[k]);
            printf("%d\n",s4->data);
            }
            break;

        }
    }while(ch!='s');
    printf("%d %d %d %d\n",counta,countb,countc,countd);
    return 0;
}