#include<iostream>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        long long i;
        i=1;
        int j;
        for(j=0;j<n;j++){
            i*=2;
        }
        cout<<2<<"^"<<n<<" = "<<i;
    }
    return 0;
}
