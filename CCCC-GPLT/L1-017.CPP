#include<iostream>
#include<iomanip>
using namespace std;
int main(){

    string str;
    while(cin>>str){

        int wei;
        wei = str.size();
        double fu;
        fu=0;
        double ou;
        int two;
        two=0;
        ou=0;

        if(str[0]=='-'){
            wei-=1;
            fu=1;
        }
        if((int)(str[str.size()-1]-'0')%2==0){
            ou=1;
        }

        int i;
        for(i=0;i<str.size();i++){
            if(str[i]=='2'){
                two++;
            }
        }

        double res;
        res = (double)two/(double)wei;
        res*=(ou+1);
        res*=(fu*0.5+1);

        cout<<fixed<<setprecision(2)<<res*100<<"%"<<endl;

    }
    return 0;
}
