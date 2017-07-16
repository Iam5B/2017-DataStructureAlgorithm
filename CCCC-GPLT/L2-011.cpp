#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int arrH[30];
int arrZ[30];
typedef struct N{
    struct N *rchild;
    struct N *lchild;
    int data;
}*TNode;

int lp[30]={0};
int arr[30][30]={0};

void dp(TNode t,int depth){
    if(t==NULL){
        return;
    }
    arr[depth][lp[depth]++]=t->data;
    dp(t->lchild,depth+1);
    dp(t->rchild,depth+1);
}
void trav(TNode t){
    if(!t){
        return;
    }
    trav(t->lchild);
    trav(t->rchild);
    TNode temp;
    temp=t->lchild;
    t->lchild=t->rchild;
    t->rchild=temp;
    return;
}
TNode create(int xs,int xe,int zs,int ze){

    if((xe<xs)||(ze<zs)){
        return NULL;
    }
    int root=arrH[xs];
    int i;
    for(i=zs;i<=ze;i++){
        if(arrZ[i]==root){
            break;
        }
    }
    TNode p;
    p=(TNode)malloc(sizeof(N));
    p->data=root;
    p->lchild=create(xs+1,xs+(i-zs),zs,i-1);
    p->rchild=create(xs+i-zs+1,xe,i+1,ze);
    return p;
}

int main(){
    int n;
    cin>>n;
    int i;
    for(i=0;i<n;i++){
        cin>>arrZ[i];
    }
    for(i=0;i<n;i++){
        cin>>arrH[i];
    }
    TNode p;
    p=create(0,n-1,0,n-1);
    trav(p);
    dp(p,0);
    int j;
    int ctr=0;
    for(i=0;lp[i]!=0;i++){
        for(j=0;j<lp[i];j++){
            if(ctr)cout<<" ";
            ctr++;
            cout<<arr[i][j];
        }
    }
    return 0;
}
