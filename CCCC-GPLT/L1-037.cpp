#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    if(m==0){
        cout<<n<<"/"<<m<<"="<<fixed<<setprecision(2)<<"Error"<<endl;
        cout.unsetf(ios_base::fixed);
    }
    else if(m<0){
        cout<<n<<"/("<<m<<")="<<fixed<<setprecision(2)<<(double)n/(double)m<<endl;
        cout.unsetf(ios_base::fixed);
    }
    else{
        cout<<n<<"/"<<m<<"="<<fixed<<setprecision(2)<<(double)n/(double)m<<endl;
        cout.unsetf(ios_base::fixed);
    }
    return 0;
}
