#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
typedef struct{
    int id;
    int money;
    int get;
}Node;
Node money[10001];
int fun(Node a,Node b){
    if(a.money>b.money){
        return 1;
    }
    else if(a.money==b.money){
        if(a.get!=b.get){
            return a.get>b.get;
        }
        else{
            return a.id<b.id;
        }
    }
    else{
        return 0;
    }
}
int main(){
    int n;
    cin>>n;
    int i;
    for(i=1;i<=n;i++){
        money[i].id=i;
        money[i].money=0;
        money[i].get=0;
    }
    for(i=1;i<=n;i++){
        int m;
        cin>>m;
        int j;
        for(j=0;j<m;j++){
            int mon;
            int per;
            cin>>per>>mon;
            money[per].money+=mon;
            money[per].get++;
            money[i].money-=mon;
        }
    }

    sort(money+1,money+1+n,fun);
    for(i=1;i<=n;i++){
        cout<<money[i].id<<" "<<fixed<<setprecision(2)<<((double)money[i].money)/100<<endl;
        cout.unsetf(ios_base::fixed);
    }
    return 0;
}
