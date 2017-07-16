#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    int n;
    char b;
    string t;
    cin>>n>>b;
    getchar();
    getline(cin,t);
    int len;
    len=t.size();
    if(n>len){
        n=n-len;
        int i;
        for(i=0;i<n;i++){
            cout<<b;
        }
        cout<<t<<endl;
    }
    else if(n<len){
        n=len-n;
        int i;
        for(i=0;i<n;i++);
        for(;i<len;i++){
            cout<<t[i];
        }
        cout<<endl;
    }
    else{
        cout<<t<<endl;
    }
    return 0;
}
