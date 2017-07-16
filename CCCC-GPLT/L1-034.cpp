#include<iostream>
using namespace std;
int main(){

    int n;
    while(cin>>n){
        int arr[1001]={0};
        int i;
        for(i=0;i<n;i++){
            int m;
            cin>>m;
            int j;
            for(j=0;j<m;j++){
                int temp;
                cin>>temp;
                arr[temp]++;
            }
        }
        int ma=arr[0];
        int maindex=0;
        for(i=0;i<=1000;i++){
            if(arr[i]>=ma){
                ma=arr[i];
                maindex=i;
            }

        }
        cout<<maindex<<" "<<ma<<endl;
    }
    return 0;
}
