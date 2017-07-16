#include<iostream>
#include<queue>
#include<stack>
using namespace std;
queue<int> xueba;
stack<int> girlB;
stack<int> boyB;
string name[100];
int namep;


int main(){
    namep=0;
    int n;
    int i;
    cin>>n;
    for(i=0;i<n/2;i++){
        int t;
        string te;
        cin>>t>>te;
        name[namep++]=te;
        if(t){
            xueba.push(1);
        }
        else{
            xueba.push(0);
        }
    }
    for(i=n/2;i<n;i++){
        int t;
        string te;
        cin>>t>>te;
        name[namep++]=te;
        if(t){
            boyB.push(i);
        }
        else{
            girlB.push(i);
        }
    }
    int ctr;
    ctr=0;
    while(!xueba.empty()){
        int tem;
        tem=xueba.front();
        xueba.pop();
        if(tem){
            cout<<name[ctr]<<" "<<name[girlB.top()]<<endl;
            girlB.pop();
        }
        else{
            cout<<name[ctr]<<" "<<name[boyB.top()]<<endl;
            boyB.pop();
        }
        ctr++;
    }
    return 0;

}
