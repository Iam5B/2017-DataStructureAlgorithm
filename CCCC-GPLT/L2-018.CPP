#include<iostream>
#include<iomanip>
using namespace std;
double B[10000]={0};
double C[10000]={0};
double Res[10000]={0};
int Bc=-1;
int Cc=-1;
int main(){
    int n;
    cin>>n;
    int i;
    for(i=0;i<n;i++){
        int ci;
        double v;
        cin>>ci>>v;
        if(ci>Bc){
            Bc=ci;
        }
        B[ci]=v;
    }
    cin>>n;
    for(i=0;i<n;i++){
        int ci;
        double v;
        cin>>ci>>v;
        if(ci>Cc){
            Cc=ci;
        }
        C[ci]=v;
    }
    int Blen=Cc;
    int Rlen=Bc;
    while(Bc>=Cc){
        double tres = B[Bc]/C[Cc];
        Res[Bc-Cc]=tres;
        int j,k;
        for(j=Bc,k=Cc;j>=(Bc-Cc);k--,j--){
            B[j]-=tres*C[k];
        }
        Bc--;
    }

    int Rnum=0;
    for(i=0;i<=Rlen;i++){
        //cout<<Res[i]<<" ";
        if(Res[i]>=0.05||Res[i]<=-0.05){
            Rnum++;
        }
    }
    if(Rnum){
        cout<<Rnum;
        for(i=Rlen;i>=0;i--){
            if(Res[i]>=0.05||Res[i]<=-0.05){
                cout<<fixed<<setprecision(0)<<" "<<setprecision(1)<<i<<" "<<Res[i];
            }
        }
        cout<<endl;
    }
    else{
        cout<<"0 0 0.0"<<endl;
    }
    int Bnum=0;
    for(i=0;i<=Blen;i++){
        if(B[i]>=0.05||B[i]<=-0.05){
            Bnum++;
        }
    }
    if(Bnum){
        cout<<Bnum;
        for(i=Blen;i>=0;i--){
            if(B[i]>=0.05||B[i]<=-0.05){
                cout<<fixed<<setprecision(0)<<" "<<setprecision(1)<<i<<" "<<B[i];
            }
        }
    }
    else{
        cout<<"0 0 0.0"<<endl;
    }
    return 0;


}
