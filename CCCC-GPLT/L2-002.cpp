#include<iostream>
#include<iomanip>
using namespace std;
int already[100000]={0};
int main(){
    int lis1[100000][2];
    int lis2[100000][2];
    int lis3[100000][2];
    int p2=0;
    int p3=0;
    int start,n;
    cin>>start>>n;
    int i;
    for(i=0;i<n;i++){
        int add;
        cin>>add;
        cin>>lis1[add][0]>>lis1[add][1];
    }
    do{
        int t = lis1[start][0];
        if(t<0){
            if(already[0-t]){
                lis3[p3][0]=start;
                lis3[p3++][1]=t;
            }
            else{
                lis2[p2][0]=start;
                lis2[p2++][1]=t;
                already[0-t]=1;
            }
        }
        else{
            if(already[t]){
                lis3[p3][0]=start;
                lis3[p3++][1]=t;
            }
            else{
                lis2[p2][0]=start;
                lis2[p2++][1]=t;
                already[t]=1;
            }
        }
        start=lis1[start][1];
    }while(start!=-1);
    for(i=0;i<p2;i++){
        int t =lis2[i][0];
        cout<<setw(5)<<setfill('0')<<t<<" "<<lis2[i][1]<<" ";
        if(i==p2-1){
            cout<<"-1"<<endl;
        }
        else{
            int q = lis2[i+1][0];
            cout<<setw(5)<<setfill('0')<<q<<endl;
        }
    }
    for(i=0;i<p3;i++){
        int t = lis3[i][0];
        cout<<setw(5)<<setfill('0')<<t<<" "<<lis3[i][1]<<" ";
        if(i==p3-1){
            cout<<"-1"<<endl;
        }
        else{
            int q = lis3[i+1][0];
            cout<<setw(5)<<setfill('0')<<q<<endl;
        }
    }
    return 0;
}
