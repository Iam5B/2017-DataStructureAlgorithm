#include<iostream>
using namespace std;
int arr[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char Arr[11]={'1','0','X','9','8','7','6','5','4','3','2'};
string q[100];
int qe[100]={0};
int check(string q){
    //错误时返回1
    //正确时返回0
    int sum;
    sum=0;
    int i;
    for(i=0;i<17;i++){
        if(q[i]>'9'||q[i]<'0'){
            return 1;
        }
        sum+=arr[i]*(q[i]-'0');
    }
    sum%=11;
    if(q[17]==Arr[sum]){
        return 0;
    }
    else{
        return 1;
    }
}
int main(){

    int n;
    while(cin>>n){
        int i;
        for(i=0;i<n;i++){
            cin>>q[i];
        }
        int sum;
        sum=0;
        for(i=0;i<n;i++){
            qe[i]=check(q[i]);
            sum+=qe[i];
        }
        if(sum){
            int j;
            for(j=0;j<n;j++){
                if(qe[j]){
                    cout<<q[j]<<endl;
                }
            }
        }
        else{
            cout<<"All passed"<<endl;
        }
    }
    return 0;
}
