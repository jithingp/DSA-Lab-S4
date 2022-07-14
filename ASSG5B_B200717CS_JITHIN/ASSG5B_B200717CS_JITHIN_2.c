#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct s{
    int dest;
    int wgt;
    struct s* nxt;
};
struct t{
    struct s* head;
};
int graph[1000][1000];
struct s* createnode(int num){
    struct s* node=(struct s*)malloc(sizeof(struct s));
    node->dest=num;
    node->wgt=-100000;
    node->nxt=NULL;
    return node;
};
void insert(struct s* node,struct t* base){
    struct s* temp=base->head;
    if(temp==NULL){
        base->head=node;
        return;
    }
    while(temp->nxt!=NULL){
        temp=temp->nxt;
    }
    temp->nxt=node;
}

void prims(int n){
    int krail[n],x,y;//
    int min=10001;
    int edges[2][n-1];
    for(int i=0;i<n;i++){   //initializing krail
        krail[i]=10001;
    }
    for(int i=0;i<n;i++){     //finding min edge
        for(int j=i;j<n;j++){
            if(graph[i][j]<min){
                min=graph[i][j];
                x=i;
                y=j;
            }
        }
    }
    edges[0][0]=x;//
    edges[1][0]=y;
    krail[x]=-1;
    krail[y]=-1;
    for(int i=0;i<n;i++){
        if(krail[i]!=-1){
            if(graph[i][x]<graph[i][y]){
                krail[i]=x;
            }
            else{
                krail[i]=y;
            }
        }
    }//
    for(int i=0;i<n-1;i++){
        int sw;
        min=10001;
        for(int j=0;j<n;j++){
            if(krail[j]!=-1&&graph[j][krail[j]]<min){
                sw=j;
                min=graph[j][krail[j]];
            }
        }
        edges[0][i]=sw;
        edges[1][i]=krail[sw];
        krail[sw]=-1;
        for(int j=0;j<n;j++){
            if(krail[i]!=-1 && graph[j][sw]<graph[j][krail[j]]){
                krail[j]=sw;
            }
        }
    }
    int sum=0;//
    for(int i=0;i<n-1;i++){
        printf("%d\n",graph[edges[0][i]][edges[1][i]]);
        sum+=graph[edges[0][i]][edges[1][i]];
    }
    printf("%d\n",sum);

}
int minweight(int weight[],int mst[],int n){
    int min=10001,minindex;
    for(int i=0;i<n;i++){
        if(mst[i]==-1 && weight[i]<min){
            min=weight[i];
            minindex=i;
        }
    }
    return minindex;
}
void prims1(int n){
    int friend[n];
    int weight[n];
    int mst[n];
    for(int i=0;i<n;i++){
        weight[i]=10001;
        mst[i]=-1;
    }
    weight[0]=0;
    friend[0]=-1;
    for(int i=0;i<n-1;i++){
        int a=minweight(weight,mst,n);
        mst[a]=1;
        for(int j=0;j<n;j++){
            if(graph[a][j]!=10001 && mst[j]==-1 && graph[a][j]< weight[j] ){
                weight[j]=graph[a][j];
                friend[j]=a;
            }
        }
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=weight[i];
    }
    printf("%d",sum);

}
int main(){
    char ch,str[10000];
    char *z;
    int n;
    scanf("%c",&ch);
    scanf("%d\n",&n);
    struct t *base[n];
    for(int i=0;i<n;i++){
        base[i]=(struct t*)malloc(sizeof(struct t));
        base[i]->head=NULL;
    }

    for(int i=0;i<n;i++){

        fgets(str,10000,stdin);
        z=strtok(str," ");
        z=strtok(NULL," ");
        while(z!=NULL){
            int num=atoi(z);
            struct s* node=createnode(num);
            insert(node,base[i]);
            z=strtok(NULL," ");
        }

    }
    for(int i=0;i<n;i++){

        fgets(str,10000,stdin);
        z=strtok(str," ");
        z=strtok(NULL," ");
        struct s* npr=base[i]->head;
        while(z!=NULL){
            int num=atoi(z);
            npr->wgt=num;
            npr=npr->nxt;
            z=strtok(NULL," ");
        }

    }
   
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            graph[i][j]=10001;
        }
    }
    for(int i=0;i<n;i++){
       struct s* temp=  base[i]->head;
       while(temp!=NULL){
           int c=temp->dest;
           int weight=temp->wgt;
           graph[i][c]=weight;
           graph[c][i]=weight;
           temp=temp->nxt;
       }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++)
    //       printf("%d ",graph[i][j]);
    //     printf("\n");  
    // }
    prims1(n);
   

    return 0;
}