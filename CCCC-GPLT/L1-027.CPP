#include<iostream>
using namespace std;
int main(){
    string t;
    while(cin>>t){

        int sql[10]={0};
        int sqlv;
        sqlv=0;
        int stau[10]={0};
        int i;
        for(i=0;i<t.size();i++){
            stau[t[i]-'0']=1;
        }
        int f;
        f=0;
        cout<<"int[] arr = new int[]{";
        for(i=9;i>=0;i--){
            if(stau[i]){
                if(f++)cout<<',';
                sql[i]=sqlv++;
                cout<<i;
            }
        }
        cout<<"};";
        cout<<endl;
        cout<<"int[] index = new int[]{";
        f=0;
        for(i=0;i<t.size();i++){
            if(f++)cout<<',';
            cout<<sql[t[i]-'0'];
        }
        cout<<"};"<<endl;
    }
    return 0;
}
