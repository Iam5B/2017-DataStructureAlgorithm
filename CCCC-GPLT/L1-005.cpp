#include<iostream>
using namespace std;
typedef struct S{
    string num;
    int id;
}stud;
stud arr[10000];
int main(){
    int n;
    while(cin>>n){
        int i;
        for(i=0;i<n;i++){
            string num;
            int key;
            int id;
            cin>>num>>key>>id;
            arr[key].num=num;
            arr[key].id=id;
        }
        int m;
        cin>>m;
        for(i=0;i<m;i++){
            int key;
            cin>>key;
            cout<<arr[key].num<<" "<<arr[key].id<<endl;
        }
    }
    return 0;
}
