#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    char arr[100][100];
    string t;
    int n;
    cin>>n;
    getchar();
    getline(cin,t);
    int mis;
    mis =(n-(t.size()%n))%n;
    int i;
    for(i=0;i<mis;i++){
        t+=' ';
    }
    int cols;
    cols=t.size()/n;
    int j;
    int cnt;
    cnt=0;
    for(i=cols-1;i>=0;i--){
        for(j=0;j<n;j++){
            arr[i][j]=t[cnt];
            cnt++;
        }
    }
    for(j=0;j<n;j++){
        for(i=0;i<cols;i++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }
    return 0;
}
