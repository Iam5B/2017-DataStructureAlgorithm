#include<iostream>
#include<math.h>
#include<cmath>
#include<iomanip>
#include<stack>
using namespace std;
int paren[100000]={0};
int level[100000]={0};
stack<int> del;
stack<double> bei;
double lev(int i){
    if(level[i]){
        return level[i];
    }
    if(i==0){
        return 0;
    }
    else{
        double res = 1+lev(paren[i]);
        level[i] = res;
        return res;
    }
}
int main(){
    int n;
    double ini;
    double per;
    cin>>n>>ini>>per;
    per = (100-per)/100;
    int i;
    int j;
    int m;
    int temp;
    for(i=0;i<n;i++){
        cin>>m;
        for(j=0;j<m;j++){
            cin>>temp;
            paren[temp]=i;
        }
        if(m==0){
            del.push(i);
            double dtemp;
            cin>>dtemp;
            bei.push(dtemp);
        }
    }
    double sum=0;
    while(!del.empty()){
        double tbei;
        int boy;
        tbei=bei.top();
        bei.pop();
        boy=del.top();
        del.pop();
        sum+=(double)tbei * ini * pow(per,lev(boy));
    }
    cout<<(int)sum<<endl;
    return 0;
}
