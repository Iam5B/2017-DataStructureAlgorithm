#include<iostream>
using namespace std;
int main(){
    string t;
    while(cin>>t){
        int arr[10]={0};
        int i;
        for(i=0;i<t.size();i++){
            arr[(int)(t[i]-'0')]++;
        }
        for(i=0;i<10;i++){
            if(arr[i]){
                cout<<i<<":"<<arr[i]<<endl;
            }
        }
    }
    return 0;
}
