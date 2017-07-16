#include<iostream>
using namespace std;
int toint(string t){
    int tar;
    tar=0;
    int i;
    for(i=0;i<4;i++){
        tar*=10;
        tar+=(t[i]-'0');
    }
    return tar;
}
string tostr(int t){
    char tar[4];
    tar[3]=t%10+'0';
    t/=10;
    tar[2]=t%10+'0';
    t/=10;
    tar[1]=t%10+'0';
    t/=10;
    tar[0]=t%10+'0';
    string s(tar);
    return s;
}

int judge(string t,int n){
    int arr[10]={0};
    int i;
    for(i=0;i<4;i++){
        arr[t[i]-'0']=1;
    }
    int cnt;
    cnt=0;
    for(i=0;i<10;i++){
        if(arr[i]){
            cnt++;
        }
    }
    if(cnt==n)return 1;
    else return 0;
}
int main(){
    int y;
    int n;
    while(cin>>y>>n){

    int cnt;
    cnt=0;
    string t;
    t=tostr(y);
    while(!judge(t,n)){
        y++;
        cnt++;
        t=tostr(y);
    }
    cout<<cnt<<" "<<t[0]<<t[1]<<t[2]<<t[3]<<endl;
    }
    return 0;
}
