#include<iostream>
#include<algorithm>
using namespace std;
bool guan[100000000]={0};
int arr2[10000]={0};
string arr1[10000];
int arr1p=0;
typedef struct{
    double num;
    string str;
}Node;
Node arr3[10000];
int fun(Node a,Node b){
    return a.str<b.str;
}
int arr3p=0;
int main(){
    int n;
    cin>>n;
    int i;
    for(i=0;i<n;i++){
        string q;
        cin>>q;
        int a1=(q[0]-'0')*1000000;
        int a2=(q[1]-'0')*10000;
        int a3=(q[2]-'0')*100;
        int a4=(q[3]-'0')*1;
        guan[a1+a2+a3+a4]=1;
    }
    cin>>n;
    double sum=0;
    for(i=0;i<n;i++){
        string q;
        int t;
        cin>>q>>t;
        int a1=(q[0]-'0')*1000000;
        int a2=(q[1]-'0')*10000;
        int a3=(q[2]-'0')*100;
        int a4=(q[3]-'0')*1;
        if(guan[a1+a2+a3+a4]){
            sum+=t;
            continue;
        }
        else{
            sum+=t;
            arr2[arr1p]=t;
            arr1[arr1p++]=q;
        }
    }
    double ave = sum/(double)n;

    for(i=0;i<arr1p;i++){
        if((double)arr2[i]>ave){
            arr3[arr3p].num=arr2[i];
            arr3[arr3p++].str=arr1[i];
        }
    }
    if(arr3p){
        sort(arr3,arr3+arr3p,fun);
        for(i=0;i<arr3p;i++){
            cout<<arr3[i].str<<endl;
        }
    }
    else{
        cout<<"Bing Mei You"<<endl;
    }

    return 0;
}
