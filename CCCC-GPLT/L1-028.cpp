#include<iostream>
#include "math.h"
using namespace std;
int main(){
    int m;
    while(cin>>m){
        int j;
        for(j=0;j<m;j++){
            long long n;
            cin>>n;
            long long n_2=(long long)sqrt((long double)n)+2;
            long long i;
            int flag=0;
            for(i=2;i<=n_2;i++){
                if(!(n%i)){
                    flag=1;
                    break;
                }
            }
            if(n==2||n==3){
                flag=0;
            }
            if(n==1){
                flag=1;
            }
            if(flag){
                cout<<"No"<<endl;
            }
            else{
                cout<<"Yes"<<endl;
            }

        }


    }


	return 0;
}
