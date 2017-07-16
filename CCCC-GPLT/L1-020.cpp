#include<iostream>
#include<string.h>
using namespace std;
int parse(string h){
    return (h[0]-'0')*10000 + (h[1]-'0')*1000 + (h[2]-'0')*100 + (h[3]-'0')*10 + (h[4]-'0');
}
int arr[1000000]={0};
int main(){
    int n;
    while(cin>>n){
        memset(arr,0,sizeof(arr));
        int i;
        for(i=0;i<n;i++){
            int m;
            cin>>m;
            if(m==1){string t;cin>>t;continue;}
            int j;
            for(j=0;j<m;j++){
                string t;
                cin>>t;
                int te;
                te=parse(t);
                arr[te]=1;
            }
        }
        int q;
        cin>>q;
        int ctr;
        ctr=0;
        for(i=0;i<q;i++){
            string t;
            cin>>t;
            int te;
            te=parse(t);
            if(!arr[te]&&ctr){
                cout<<" ";
            }
            if(!arr[te]){
                cout<<t;
                ctr++;
                arr[te]=1;
            }
        }
        if(!ctr){
            cout<<"No one is handsome";
        }
        cout<<endl;
    }

}
