#include<iostream>
using namespace std;
int main(){

    string t;
    while(cin>>t){
        int i;
        for(i=0;i<t.size();i++){
            string out;
            switch(t[i]){
            case '-':out="fu";break;
            case '1':out="yi";break;
            case '2':out="er";break;
            case '3':out="san";break;
            case '4':out="si";break;
            case '5':out="wu";break;
            case '6':out="liu";break;
            case '7':out="qi";break;
            case '8':out="ba";break;
            case '9':out="jiu";break;
            case '0':out="ling";break;
            }
            cout<<out;
            if(i!=t.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
