#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<windows.h>
using namespace std;
typedef struct N{
    N *l;
    N *r;
    int data;
}*TNode;
int arrZ[1000];
int arrX[1000];
int ctr=0;
int fun1(int a,int b){
    return a<b;
}
int fun2(int a,int b){
    return a>b;
}
int wrongflag=0;
int leftsmall;
TNode Tree(int xs,int xe,int zs,int ze){

    //cout<<xs<<" "<<xe<<" "<<zs<<" "<<ze<<" "<<endl;
    if(wrongflag==1){
        return NULL;
    }
    if(xe-xs<0&&ze-zs<0){
        return NULL;
    }
    else if(!(xe-xs<0&&ze-zs<0)&&!(xe-xs==ze-zs)){
        wrongflag=1;
        return NULL;
    }
    else if(xe-xs==ze-zs&&xe==xs&&arrX[xs]!=arrZ[zs]){
        wrongflag=1;
        return NULL;
    }
    TNode p;
    p=(TNode)malloc(sizeof(N));
    p->data=arrX[xs];
    int tomatch = arrX[xs];
    int i;
    if(!leftsmall)
        for(i=ze;i>=zs;i--){
            if(arrZ[i]==tomatch)break;
        }
    else
        for(i=zs;i<=ze;i++){
            if(arrZ[i]==tomatch)break;
        }
    //cout<<"i="<<i<<endl;

        p->l=Tree(xs+1,xs+(i-zs),zs,i-1);
        p->r=Tree(xs+(i-zs)+1,xe,i+1,ze);

    return p;
}
void HOU(TNode p){
    if(p==NULL){
        return;
    }
    else{
            HOU(p->l);
            HOU(p->r);
            if(ctr){cout<<" ";}
            ctr++;
            cout<<p->data;
    }
}

int main(){
    int n;
    int i;
    cin>>n;
    for(i=0;i<n;i++){
        int temp;
        cin>>temp;
        arrZ[i]=temp;
        arrX[i]=temp;
    }
    if(arrX[0]<=arrX[n-1]){
        sort(arrZ,arrZ+n,fun1);
        leftsmall=1;
    }
    else{
        sort(arrZ,arrZ+n,fun2);
        leftsmall=0;
    }
    TNode tre;
    tre = Tree(0,n-1,0,n-1);
    if(wrongflag){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        HOU(tre);
        cout<<endl;
    }
    return 0;
}
