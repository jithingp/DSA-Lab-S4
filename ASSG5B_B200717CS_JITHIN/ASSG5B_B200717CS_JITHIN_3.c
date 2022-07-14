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
int graph[1000][1000],n;
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
int minweight(int weight[],int mst[]){
    int min=10001,minindex;
    for(int i=0;i<n;i++){
        if(mst[i]==-1 && weight[i]<=min){
            min=weight[i];
            minindex=i;
        }
    }
    return minindex;
}
void prims1(int source,int weight[]){
    //printf("%d\n",n);
    //int weight[n];//
    int mst[n];
    for(int i=0;i<n;i++){
        weight[i]=10001;
        mst[i]=-1;
    }
    weight[source]=0;
    for(int i=0;i<n-1;i++){
        int a=minweight(weight,mst);
        mst[a]=1;
        for(int j=0;j<n;j++){
            if(graph[a][j]!=10001 && mst[j]==-1 && weight[a]!=10001 && (weight[a]+graph[a][j])< weight[j] ){
                weight[j]=graph[a][j]+weight[a];
            }
        }
    }//

    
}
int main(){
    char str[10000];
    char *z;
    int nerland;//
    scanf("%d\n",&n);
 
    //printf("%d,,,\n",n);
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
           //graph[c][i]=weight;
           temp=temp->nxt;
       }
    }
    char sel[4];
    int source,destination;
    while(1){
        scanf("%s ",&sel);//
        if(strcmp(sel,"apsp")==0){
            scanf("%d\n",&source);
            int weight[n];
            prims1(source,weight);
            for(int i=0;i<n;i++){
                if(weight[i]==10001)
                    printf("%s ","INF");
                else    
                    printf("%d ",weight[i]);
            }
                
            printf("\n");
        }
        else if(strcmp(sel,"sssp")==0){
            scanf("%d%d\n",&source,&destination);
            int weight[n];
            prims1(source,weight);
            if(weight[destination]==10001)
                printf("%s\n","UNREACHABLE");
            else    
            printf("%d\n",weight[destination]);
        }
        else if(strcmp(sel,"stop")==0){
            break;
        }
    }

     return 0;
    }