#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
string test;
string del;

int main(){

    while(getline(cin,test)){
        char t;
        getline(cin,del);
        int arr[1000]={0};
        int i;
        for(i=0;i<del.size();i++){
                arr[del[i]]=1;
        }

        for(i=0;i<test.size();i++){
            if(arr[test[i]]){
                continue;
            }
            else{
                cout<<test[i];
            }
        }
        cout<<endl;
        t = getchar();

    }

    return 0;

}
