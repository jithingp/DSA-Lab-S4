#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,k;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("%d ",i);
        for(int j=0;j<n;j++){
            scanf("%d",&k);
            if(k==1){
                printf("%d ",j);
            }
        }
        printf("\n");
    }

    return 0;
}