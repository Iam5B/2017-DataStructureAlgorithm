#include<iostream>
using namespace std;
void print(int depth,char m,int left){
    int t = depth;
    int maxwid = t*2-1;
    int i;
    for(i=0;maxwid-2*i>=1;i++){
        int j;
        for(j=0;j<i;j++){
            cout<<" ";
        }
        for(j=0;j<maxwid-2*i;j++){
            cout<<m;
        }
        cout<<endl;
    }
    i--;
    i--;
    for(;i>=0;i--){
        int j;
        for(j=0;j<i;j++){
            cout<<" ";
        }
        for(j=0;j<maxwid-2*i;j++){
            cout<<m;
        }
        cout<<endl;
    }
    cout<<left<<endl;

    return ;

}
int main(){
    int n;
    char m;
    int depth;
    while(cin>>n>>m){
        if(n==0){
            cout<<0<<endl;
            continue;
        }
        n--;
        depth=1;
        int i;
        for(i=3;(n-2*i)>=0;i+=2){
            depth++;
            n-=2*i;
        }
        print(depth,m,n);
    }
    return 0;
}
