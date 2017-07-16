#include<iostream>
#include<math.h>
using namespace std;
int main(){

    int n;
    while(cin>>n){
        int i;
        for(i=0;i<n;i++){
            double height,weight;
            double bzweight;
            cin>>height>>weight;
            bzweight=(height-100)*0.9*2;
            double cha;
            cha = fabs(weight-bzweight);
            if(cha+0.00000001>=0.1*bzweight){

                if(weight>=bzweight){
                    cout<<"You are tai pang le!"<<endl;
                }
                else{
                    cout<<"You are tai shou le!"<<endl;
                }
            }
            else{
                cout<<"You are wan mei!"<<endl;
            }
        }
    }
    return 0;
}
