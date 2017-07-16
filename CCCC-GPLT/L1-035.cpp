#include<iostream>
using namespace std;
string arr[100];
int arrp;
int main(){
    arrp=0;
    string t;
    cin>>t;
    while(t.compare(".")){
        arr[arrp++]=t;
        cin>>t;
    }
    if(arrp<2){
        cout<<"Momo... No one is for you ..."<<endl;
    }
    else if(arrp>=2&&arrp<14){
        cout<<arr[1]<<" is the only one for you..."<<endl;
    }
    else{
        cout<<arr[1]<<" and "<<arr[13]<<" are inviting you to dinner..."<<endl;
    }
    return 0;
}
