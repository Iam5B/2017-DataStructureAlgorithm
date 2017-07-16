#include<iostream>
using namespace std;
int main(){

    int n;
    while(cin>>n){
        int ji;
    int ou;
    ji=0;
    ou=0;
    int t;
    int i;
        for(i=0;i<n;i++){
            cin>>t;
            if(t%2){
                ji++;
            }
            else{
                ou++;
            }
        }
        cout<<ji<<" "<<ou<<endl;
    }

    return 0;
}
