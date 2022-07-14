#include<stdio.h>
#include<stdlib.h>
struct s{
    int key;
    int degree;
    struct s* child;
    struct s* parent;
    struct s* sibling;
    struct s* nxt;
};
struct h{
    struct s* head;
};
struct h* makeheap(){
    struct h* heap=(struct h*)malloc(sizeof(struct h));
    heap->head=NULL;
    return heap;
}
void binomiallink(struct s* a,struct s* b){
    
    a->parent=b;
    a->sibling=b->child;
    b->child=a;
    b->degree++;
}
struct s* heapmerge(struct s* h1,struct s* h2){
    struct s* tail3=(struct s*)malloc(sizeof(struct s));
    if(!h1)
    return h2;
    if(!h2)
    return h1;
    
    struct s* head3=tail3,*tail2=h2,*tail1=h1;
  

    while(tail1!=NULL && tail2!=NULL){
        if(tail1->degree<=tail2->degree){
            tail3->sibling=tail1;
            tail3=tail1;
            tail1=tail1->sibling;
        }
        else{
            tail3->sibling=tail2;
            tail3=tail2;
            tail2=tail2->sibling;
        }
    }
    if(tail1==NULL){
        while(tail2!=NULL){
            tail3->sibling=tail2;
            tail3=tail2;
            tail2=tail2->sibling;
        }
    }
    else if(tail2==NULL){
        while(tail1!=NULL){
            tail3->sibling=tail1;
            tail3=tail1;
            tail1=tail1->sibling;
        }
    }
    return head3->sibling;
}
struct h* union1(struct h* h1,struct h* h2){
    struct h* h3=makeheap();
    h3->head=heapmerge(h1->head,h2->head);
    if(h3->head==NULL){
        return h3;
    }
    struct s* prevx=NULL;
    struct s* x=h3->head;
    struct s* nextx=x->sibling;
    while(nextx!=NULL){
        if((x->degree!=nextx->degree) || (nextx->sibling!=NULL && nextx->sibling->degree == x->degree)){
            prevx=x;
            x=nextx;
        }
        else{
            if(x->key <= nextx->key){
                x->sibling=nextx->sibling;
                binomiallink(nextx,x);
            }
            else{
                if(prevx==NULL){
                    h3->head=nextx;
                }
                else{
                    prevx->sibling=nextx;
                }
                binomiallink(x,nextx);
                x=nextx;
            }
        }
        
        nextx=x->sibling;
    }
    return h3;
}
struct s* createnode(int k){
    struct s* node=NULL;
    node=(struct s*)malloc(sizeof(struct s));
    node->child=NULL;
    node->degree=0;
    node->key=k;
    node->parent=NULL;
    node->sibling=NULL;
    node->nxt=NULL;
    return node;
}
struct h* insert(struct h* h1,int k){
    struct s* y=createnode(k);
    struct h* h2=makeheap();
    h2->head=y;
    struct h* h3=union1(h1,h2);
    return h3;
}

void prin(struct s* qhead,struct s* qtail){
    if(qhead==NULL){
        return;
    }
    struct s* node=qhead->child;
    while(node!=NULL){
        qtail->nxt=node;
        qtail=qtail->nxt;
        node=node->sibling;
    }
    printf("%d ", qhead->key);
    
    struct s* node1=qhead->nxt;
    qhead->nxt=NULL;
    prin(node1,qtail);

}
struct s* findnpr(struct s* qhead,struct s* qtail,int key){
     if(qhead==NULL){
        return NULL;
    }
    struct s* node=qhead->child;
    while(node!=NULL){
        qtail->nxt=node;
        qtail=qtail->nxt;
        node=node->sibling;
    }
    if(qhead->key==key){
        return qhead;
    }
    
    struct s* node1=qhead->nxt;
    qhead->nxt=NULL;
    return findnpr(node1,qtail,key);

}
int heapminimum(struct s* node){
    int min=node->key;
    while(node!=NULL){
        if(node->key<min)
        min=node->key;
        node=node->sibling;
    }
    return min;
}
struct s* revlist(struct s* node){
    if(node==NULL||node->sibling==NULL){
        return node;
    }
    struct s* prev=NULL;
    struct s* cur=node;
    //struct s* nxt1=node->sibling;
    struct s* nxt1=NULL;

    while(cur!=NULL){
        nxt1=cur->sibling;
        cur->sibling=prev;
        prev=cur;
        cur=nxt1;
    }
    return prev;
}
struct h* extractmin(struct h* h1,int min){
    
    struct s* cmin=NULL;
    struct s* node=h1->head;
    if(node->key==min){
        h1->head=node->sibling;
        cmin=node->child;
        if(cmin!=NULL)
        cmin->parent=NULL;
    }
    else{
    while(node->sibling!=NULL){
        if(node->sibling->key==min){
        cmin=node->sibling->child;
        if(cmin!=NULL)
        cmin->parent=NULL;
        node->sibling=node->sibling->sibling;
        break;
        }
        node=node->sibling;
    }
    }
    struct h* h2=(struct h*)malloc(sizeof(struct h));
    h2->head=revlist(cmin);
    h1=union1(h1,h2);
    return h1;
}
void decreasekey(struct h* heap,struct s* node, int newkey ){
    node->key=newkey;
    struct s* wriman=node;
    struct s* zri=wriman->parent;
    while(zri!=NULL && wriman->key < zri->key){
        int cc=wriman->key;
        wriman->key=zri->key;
        zri->key=cc;
        wriman=zri;
        zri=wriman->parent;
    }
}
struct h*  delete(struct h* str, struct s* x){

    decreasekey(str,x,-9999999);
    int min=heapminimum(str->head);
    str=extractmin(str,min);
    return str;
}
int main(){
struct h* h1=(struct h*)malloc(sizeof(struct h));
h1->head=NULL;
struct s* qhead=NULL;
struct s* qtail=NULL;
struct s* test=NULL;
int k;
    char ch;
    do{
        scanf("%c", &ch);
        switch(ch){
            case 'i':
            scanf("%d", &k);
            h1=insert(h1,k);
            break;
            case 'p':
            qhead=h1->head;
            qtail=h1->head;
            while(qtail->sibling!=NULL){
                qtail->nxt=qtail->sibling;
                qtail=qtail->sibling;
            }
            prin(qhead,qtail);
            printf("\n");
            break;
            case 'm':
            int min=heapminimum(h1->head);
            printf("%d\n",min);
            break;
            case 'x':
            if(h1->head==NULL){
                printf("%d\n",-1);
            }
            else{
                int min=heapminimum(h1->head);
                printf("%d\n",min);
                h1=extractmin(h1,min);
            }
            
            break;
            case 'r':
            int x1,k1;
            scanf("%d %d",&x1,&k1);
            qhead=h1->head;
            qtail=h1->head;
            while(qtail->sibling!=NULL){
                qtail->nxt=qtail->sibling;
                qtail=qtail->sibling;
            }
            test=findnpr(qhead,qtail,x1);
            if(test==NULL)
            printf("%d\n",-1);
            else{
                if(k1>x1)
                printf("%d\n",-1);
                else
                {
                    printf("%d\n",x1-k1);
                    decreasekey(h1,test,x1-k1);
                }

            }
            break;
            case 'd':
            scanf("%d",&k1);
            qhead=h1->head;
            qtail=h1->head;
            while(qtail->sibling!=NULL){
                qtail->nxt=qtail->sibling;
                qtail=qtail->sibling;
            }
            test=findnpr(qhead,qtail,k1);
            if(test==NULL)
            printf("%d\n",-1);
            else{
                printf("%d\n",k1);
                h1= delete(h1,test);
            }
            break;

        }
    }while(ch!='e');

    return 0;
}