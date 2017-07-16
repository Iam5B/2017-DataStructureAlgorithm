#include<iostream>
#include<math.h>
using namespace std;
typedef struct{
    long long fenzi;
    long long fenmu;
}num;

num arr[100];

long long GYS(long long a,long long b)
{
    return b==0?a:GYS(b,a%b);
}
long long GBS(long long a,long long b){
    return a*b/GYS(a,b);
}
int main(){
    int n;
    while(cin>>n){
        int i;
        for(i=0;i<n;i++){
            char t;
            cin>>arr[i].fenzi>>t>>arr[i].fenmu;

        }

        long long sum_fenmu=1;
        long long sum_fenzi=0;

        for(i=0;i<n;i++){

            if(sum_fenmu%arr[i].fenmu!=0){
                sum_fenmu*=arr[i].fenmu;
            }

        }

        for(i=0;i<n;i++){

            sum_fenzi+=arr[i].fenzi*(sum_fenmu/arr[i].fenmu);

        }

        long long gongyin = GYS(sum_fenzi,sum_fenmu);

        sum_fenzi/=gongyin;
        sum_fenmu/=gongyin;

        long long header;

        if(sum_fenzi<0){
            cout<<"-";
            sum_fenzi = 0- sum_fenzi;
        }

        header = sum_fenzi/sum_fenmu;

        sum_fenzi%=sum_fenmu;

        if(header==0&&sum_fenzi==0){

            cout<<0<<endl;

        }
        else if(header!=0&&sum_fenzi==0){
            cout<<header<<endl;
        }
        else if(header!=0&&sum_fenzi!=0){
            cout<<header<<" "<<sum_fenzi<<"/"<<sum_fenmu<<endl;
        }
        else if(header==0&&sum_fenzi!=0){
            cout<<sum_fenzi<<"/"<<sum_fenmu<<endl;
        }
    }
    return 0;

}
