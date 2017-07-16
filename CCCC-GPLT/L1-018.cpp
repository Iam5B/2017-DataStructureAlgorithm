#include<iostream>
using namespace std;
int main(){

    string str;
    while(cin>>str){

        int hour;

        int minu;

        hour = (str[0]-'0')*10 + (str[1]-'0')*1;

        minu = (str[3]-'0')*10 + (str[4]-'0')*1;

        if(hour>=0&&hour<=11||hour==12&&minu==0){
            cout<<"Only "<<str[0]<<str[1]<<":"<<str[3]<<str[4]<<".  Too early to Dang."<<endl;
            continue;
        }
        else{
            int n;
            if(minu==0){

                n=hour-12;
            }
            else {
                n=hour-11;
            }
            for(;n>=1;n--){
                cout<<"Dang";
            }
            cout<<endl;
            continue;
        }

    }

}
