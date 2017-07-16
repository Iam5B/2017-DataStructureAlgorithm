#include<iostream>
#include<math.h>
using namespace std;
int main(){

    long long n;
    while(cin>>n){
        int m;
        double b;
        b=sqrt((double)n);
        m=(int)b+1;
        int length = 1;
        int maxlength = 1;
        long long maxstart;
        int start = 2;
        int sum;
        long long i;
        if(n==1){
            cout<<0<<endl;
            continue;
        }
        if(n%2==0){
            maxstart=2;
            for(i=2;i<=m;i++){
                start = i;
                sum=i;
                length = 1;
                int j;
                for(j=i+1;j<=m;j++){
                    if(n%(sum*j)==0){
                        length++;
                        sum*=j;
                    }
                    else{
                        if(length>maxlength){
                            maxlength=length;
                            maxstart=start;
                        }
                        break;
                    }
                }
            }
        }
        else{
            int flag = 0;
            for(i=3;i<=m;i++){
                if(n%i==0){
                    maxstart=i;
                    flag = 1;
                    break;
                }
            }
            if(!flag)
                maxstart=n;

        }
        cout<<maxlength<<endl;
        for(i=0;i<maxlength;i++){
            cout<<maxstart+i;
            if(i!=maxlength-1){
                cout<<"*";
            }
        }
        cout<<endl;
    }
    return 0;
}
