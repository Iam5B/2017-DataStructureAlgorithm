#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
bool arr[10000000]={0};

typedef struct{
    int kind;
    string name;
    int same;
}peo;

int fun(peo a,peo b){
    if(a.kind>b.kind){
        return 1;
    }
    if(b.kind>a.kind){
        return 0;
    }
    else{
        return a.same<b.same;
    }
}

int main(){
    peo People[1001];
    int p=0;
    int i;
    for(i=0;i<1001;i++){
        People[i].kind=0;
        People[i].same=0;
    }
    int n;
    cin>>n;
    for(i=0;i<n;i++){
        memset(arr,0,sizeof(arr));
        cin>>People[i].name;
        int m;
        cin>>m;
        int j;
        for(j=0;j<m;j++){
            int temp;
            cin>>temp;
            if(!arr[temp]){
                arr[temp]++;
                People[i].kind++;
            }
            else{
                People[i].same++;
            }
        }
    }
    sort(People,People+n,fun);
    for(i=0;i<3;i++){
        if(i){
            cout<<" ";
        }
        if(People[i].kind){
            cout<<People[i].name;
        }
        else{
            cout<<"-";
        }
    }
    cout<<endl;
    return 0;
}
