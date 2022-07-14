#include<stdio.h>
#include<stdlib.h>
struct s{
    int src;
    int rp;
    int wgt;
};

void checkneg(struct s* edges[],int v,int e){
    int dooram[v];//
    for(int i=0;i<v;i++){
        dooram[i]=100000;
    }
    dooram[0]=0;//
    for(int i=1;i<v;i++){
        for(int j=0;j<e;j++){
            int a=edges[j]->src;
            int b=edges[j]->rp;
            int weight=edges[j]->wgt;
            if(dooram[a]!=100000 && (dooram[a]+weight)<dooram[b])
                dooram[b]=dooram[a]+weight;

        }
    }//24
    for(int i=0;i<e;i++){
        int a=edges[i]->src;
        int b=edges[i]->rp;
        int weight=edges[i]->wgt;
        if(dooram[a]!=100000 && (dooram[a]+weight)<dooram[b]){
            printf("%d\n",1);
            return;
        }
    }
    printf("%d\n",-1);//

}
int main(){
    int v,e;
    scanf("%d%d",&v,&e);
    struct s* edges[e];//
    //*edges=(struct s*)malloc(sizeof(struct s)*e);
    for(int i=0;i<e;i++){
        edges[i]=(struct s*)malloc(sizeof(struct s));
        scanf("%d%d%d",&edges[i]->src,&edges[i]->rp,&edges[i]->wgt);
        //printf("%d %d %d\n",edges[i]->src,edges[i]->rp,edges[i]->wgt);

    }
    //
    checkneg(edges,v,e);

    return 0;
}