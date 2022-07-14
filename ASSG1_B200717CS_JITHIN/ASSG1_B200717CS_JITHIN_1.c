#include<stdio.h>
#include<stdlib.h>
struct s{
    int key;
    struct s* left;
    struct s* right;
    struct s* p;
};
struct ll{
    struct s* top;
};
struct e{
    struct s* data;
    struct e* nxt;
};
struct q{
    struct e* head;
    struct e* tail;
};
struct s* createnode(int k){
    struct s* selli=NULL;
    selli=(struct s*)malloc(sizeof(struct s));
    selli->key=k;
    selli->p=NULL;
    selli->left=NULL;
    selli->right=NULL;
    return selli;
}
void push(struct q* que,struct s* sel){
    struct e* w=(struct e*)malloc(sizeof(struct e));
    w->data=sel;
    w->nxt=NULL;
    if(que->head==NULL){
        que->head=w;
        que->tail=w;
        return;
    }
    que->tail->nxt=w;
    que->tail=w;
}
void insert(struct ll* tree,struct s* k){
    struct s* sel=tree->top;
    if(sel==NULL){
        tree->top=k;
        return;
    }
    struct q* que=NULL;
    que=(struct q*)malloc(sizeof(struct q));
    que->head=NULL;
    que->tail=NULL;
    push(que,sel);
    while(que->head!=NULL){
        struct e* omas=que->head;
        que->head=que->head->nxt;

        if(omas->data->left!=NULL)
        push(que,omas->data->left);
        else{
            omas->data->left=k;
            return;
        }

        if(omas->data->right!=NULL)
        push(que,omas->data->right);
        else{
            omas->data->right=k;
            return;
        }
    }

}
void print(struct s* node){
    if(node==NULL){
        printf("( ) ");
        return;
    }
 
    printf("( ");
    printf("%d ",node->key);
    print(node->left);
    print(node->right);
    printf(") ");
}
int main(){
    struct s* amul=NULL,*z=NULL;
    amul=(struct s*)malloc(sizeof(struct s));
    struct ll* tree=NULL;
    tree=(struct ll*)malloc(sizeof(struct ll));
    tree->top=NULL;
    char ch;
    int k;
    do
    {
       scanf("%c",&ch);
       switch(ch){
           case 'i':
           scanf("%d",&k);
           z=createnode(k);
           insert(tree,z);
           break;
           case 'p':
           print(tree->top);
           printf("\n");
           break;
       }
    } while (ch!='e');
    
 return 0;
}