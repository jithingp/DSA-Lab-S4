#include<stdio.h>
#include<stdlib.h>
#include<math.h>
// struct s{
//     int rev;
// };
int hash1(int ele,int a1,int a2,int i,int siz){
    int m=ele%siz;
    int m1=(m+(a1*i)+(a2*i*i))%siz;
    return m1;
}
int hash2(int ele,int i,int siz,int rael){
    int m=ele%siz;
    int mm=rael-(ele%rael);
    int m1=(m+(i*mm))%siz;
    return m1;
}
void insert(int arr[],int ele,char sel,int a1,int a2,int siz,int rael){
    int index,i=0,flag=0;
    if(sel=='a'){
        while(i<=siz){
        index=hash1(ele,a1,a2,i,siz);
        if(arr[index]==-1){
            flag=1;
            break;
        }
        else
            i++;    
        }
        //arr[index]=(struct s*)malloc(sizeof(struct s));
        if(flag==1)
        arr[index]=ele;
    }
    else{
        while(i<=siz){
            index=hash2(ele,i,siz,rael);
        if(arr[index]==-1){
            flag=1;
            break;
        }
        else
            i++;    
        }
        if(flag==1)
        arr[index]=ele;
        
    }

}
void search(int arr[],int ele,char sel,int a1,int a2,int siz,int rael){
    int index,i=0;
    if(sel=='a'){
        while(i<siz){
           index=hash1(ele,a1,a2,i,siz);
            
            if(arr[index]==ele){
                printf("%d\n",1);
                return;
            }
                i++;    
        } 
        printf("%d\n",-1);
        return;
    }
    else{
        while(i<siz){
           index=hash2(ele,i,siz,rael);
            if(arr[index]==ele){
                printf("%d\n",1);
                return;
            }
                i++;    
        } 
        printf("%d\n",-1);
        return;
    }
}
void print(int arr[],int siz){
    for(int i=0;i<siz;i++){
        printf("%d ",i);
        if(arr[i]==-1)
        printf("()\n");
        else
        printf("(%d)\n",arr[i]);
    }
}
void delete(int arr[],int ele,char sel,int a1,int a2,int siz,int rael){
    int index,i=0;
    if(sel=='a'){
        while(1){
           index=hash1(ele,a1,a2,i,siz);
            if(arr[index]==ele){
                arr[index]=-1;
                return;
            }
            i++;    
        } 
    }
    else{
        while(1){
           index=hash2(ele,i,siz,rael);
            if(arr[index]==ele){
                arr[index]=-1;
                return;
            }
            i++;    
        } 

    }
}
int calcr(int siz){
 if (siz & 1)
        siz -= 2;
    else
        siz--;
 
    int i, j;
    for (i = siz; i >= 2; i -= 2) {
        if (i % 2 == 0)
            continue;
        for (j = 3; j <= sqrt(i); j += 2) {
            if (i % j == 0)
                break;
        }
        if (j > sqrt(i))
            return i;
    }
    return 2;
}
int main(){
    char sel,ch;
    scanf("%c",&sel);
    int siz,ele,a1=0,a2=0,rael=0;
    scanf("%d",&siz);
    if(sel=='a'){
        scanf("%d%d",&a1,&a2);
    }
    else{
        if(siz<3)
        rael=0;
        else
        rael=calcr(siz);
    }
    int *arr=(int*)malloc(siz*sizeof(int));
    for(int i=0;i<siz;i++){
        arr[i]=-1;
    }
    do
    {
        scanf("%c",&ch);
        switch(ch){
            case 'i':
            scanf("%d",&ele);
            insert(arr,ele,sel,a1,a2,siz,rael);
            break;
            case 's':
            scanf("%d",&ele);
            search(arr,ele,sel,a1,a2,siz,rael);
            break;
            case 'p':
            print(arr,siz);
            break;
            case 'd':
            scanf("%d",&ele);
            delete(arr,ele,sel,a1,a2,siz,rael);
            break;

        }
    }while (ch!='t');
    
    return 0;
}