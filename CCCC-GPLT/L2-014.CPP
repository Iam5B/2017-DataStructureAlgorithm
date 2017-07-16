#include<iostream>
#include<stdio.h>
using namespace std;
int Stack[100000]={0};
int fin(int t,int bot,int top){
    int pos = (bot+top)/2;
    if(Stack[pos]<t&&Stack[pos+1]>t){
        return pos+1;
    }
    else{
        if(Stack[pos]<t){
            return fin(t,pos,top);
        }
        else{
            return fin(t,bot,pos);
        }
    }
}


int p=0;
int main(){
    int n;
    cin>>n;
    int i;

    for(i=0;i<n;i++){
        int t;
        cin>>t;
        if(t>Stack[p]){
            Stack[++p]=t;
        }
        else{
            int pos = fin(t,0,p);
            Stack[pos]=t;
        }
        /*for(int j=0;j<=p;j++){
            cout<<Stack[j]<<" ";
        }
        cout<<endl;*/
    }
    cout<<p<<endl;
    return 0;
}
