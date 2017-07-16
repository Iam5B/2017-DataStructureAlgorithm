#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
typedef struct {
    double num;
    double val;
    double ave;
}YB;
int func(YB A,YB B){
    return A.ave>B.ave;
}
int main(){
    YB arr[1000];
    int n;
    double tar;
    cin>>n>>tar;
    int i;
    for(i=0;i<n;i++){
        cin>>arr[i].num;
    }
    for(i=0;i<n;i++){
        cin>>arr[i].val;
    }
    for(i=0;i<n;i++){
        arr[i].ave=arr[i].val/arr[i].num;
    }
    sort(arr,arr+n,func);
    double totalnum=0;

    for(i=0;i<n;i++){

        tar-=arr[i].num;
        if(tar>=0){
            totalnum+=arr[i].val;
        }
        else{
            totalnum+= ((arr[i].num-(0 - tar))/arr[i].num)*arr[i].val;
            break;
        }
    }
    cout<<fixed<<setprecision(2)<<totalnum<<endl;

}
