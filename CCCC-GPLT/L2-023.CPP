#include<iostream>
using namespace std;
int arr[250000][2];
int edges;
int points;
int pointcolor[501]={0};

int main(){
    int color;
    cin>>points>>edges>>color;
    int i;
    for(i=0;i<edges;i++){
        int x,y;
        cin>>x>>y;
        arr[i][0]=x;
        arr[i][1]=y;
    }
    int m;
    cin>>m;
    for(i=0;i<m;i++){
        int j;
        int cor[501]={0};
        int cors=0;
        for(j=1;j<=points;j++){
            cin>>pointcolor[j];
            if(!cor[pointcolor[j]]){
                cors++;
                cor[pointcolor[j]]++;
            }
        }
        int k;
        int flag=0;
        for(k=0;k<edges;k++){
            if(pointcolor[arr[k][0]]==pointcolor[arr[k][1]]){
                flag=1;
                break;
            }
        }
        if(flag==0){
            if(cors!=color){
                cout<<"No"<<endl;
            }
            else{
                cout<<"Yes"<<endl;
            }
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}
