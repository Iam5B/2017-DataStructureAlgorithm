#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
void change(int &a,int &b){
    int temp = a;
    a=b;
    b=temp;
    return;
}
int fun(double a,double b){
    return a>=b;
}
int big[10000]={0};
int small[10000]={0};
int sum[10000]={0};
double ave[10000];
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    int i;
    int j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            int temp;
            cin>>temp;
            if(j==0){
                small[i]=temp;
            }
            else if(j==1){
                big[i]=temp;
                if(small[i]>big[i]){
                    //cout<<small[i]<<big[i]<<endl;
                    change(small[i],big[i]);

                }
            }
            else{
                if(temp>big[i]){
                    big[i]=temp;
                }
                if(temp<small[i]){
                    small[i]=temp;
                }
            }
            sum[i]+=temp;
        }
    }
    for(i=0;i<n;i++){
        ave[i]=(double)(sum[i]-big[i]-small[i])/(double)(m-2);

    }
    sort(ave,ave+n,fun);
    int ctr=0;
    for(i=k-1;i>=0;i--){
        if(ctr){
            cout<<" ";
        }
        ctr++;
        cout<<fixed<<setprecision(3)<<ave[i];
    }
    cout<<endl;
    return 0;
}
