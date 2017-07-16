#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int arr[50][10000];
int len[50];
typedef struct{
    int dat;
    int frm;
}N;
int func(N a,N b){
    return a.dat<b.dat;
}

void sql(int a,int b){
    N tarr[20000];
    int tlen=len[a]+len[b];
    int lena=len[a];
    int i;
    int j;
    for(i=0;i<lena;i++){
        tarr[i].dat=arr[a][i];
        tarr[i].frm=0;
    }
    for(j=0;i<tlen;i++,j++){
        tarr[i].dat=arr[b][j];
        tarr[i].frm=1;
    }
    sort(tarr,tarr+tlen,func);
    int prev = tarr[0].dat;
    int kind=1;
    int pairs=0;
    int time=1;
    int ahas=0;
    int bhas=0;
    if(tarr[0].frm==0){
        ahas=1;
    }
    else{
        bhas=1;
    }
    for(i=1;i<tlen;i++){
      if(tarr[i].dat!=prev){
            if(ahas&&bhas){
                pairs++;
            }
            ahas=bhas=0;
            kind++;
            prev=tarr[i].dat;
            if(tarr[i].frm==0){
                ahas=1;
            }
            else{
                bhas=1;
            }
        }
        else{
            if(tarr[i].frm==0){
                ahas=1;
            }
            else{
                bhas=1;
            }
        }
        if(i==tlen-1){

            if(ahas&&bhas){
                pairs++;
            }
        }
    }

    cout<<fixed<<setprecision(2)<<100*(double)pairs/(double)kind<<"%"<<endl;

}
int main(){
    int n;
    int i;
    cin>>n;
    for(i=0;i<n;i++){
        int k;
        cin>>k;
        len[i]=k;
        int j;
        for(j=0;j<k;j++){
            cin>>arr[i][j];
        }
    }
    cin>>n;
    for(i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        sql(a-1,b-1);
    }
}
