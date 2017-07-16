#include<iostream>
#include<algorithm>
using namespace std;
int arr[100000]={0};
int fun(int a,int b){
    return a<b;
}
int main(){
    int n;
    cin>>n;
    int i;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n,fun);
    int l1,l2;
    l1=n/2;
    if(n%2){
        cout<<"Outgoing #: "<<(n/2)+1<<endl;
        cout<<"Introverted #: "<<n/2<<endl;
    }
    else{
        cout<<"Outgoing #: "<<(n/2)<<endl;
        cout<<"Introverted #: "<<n/2<<endl;
    }
    long long sum=0;
    for(i=0;i<l1;i++){
        sum-=arr[i];
    }
    for(;i<n;i++){
        sum+=arr[i];
    }
    cout<<"Diff = "<<sum<<endl;
    return 0;
}
