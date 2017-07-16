#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    int n;
    cin>>n;
    int i;
    for(i=0;i<n;i++){
        char sex;
        double hei;
        cin>>sex>>hei;
        if(sex=='F'){
            cout<<fixed<<setprecision(2)<<hei*1.09<<endl;
        }
        else{
            cout<<fixed<<setprecision(2)<<hei/1.09<<endl;
        }

    }
    return 0;


}
