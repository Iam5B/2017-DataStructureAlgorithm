#include<iostream>
using namespace std;
int pre[101];
int envy[101][101]={0};
int fin(int x)
{
    int r=x;
    while ( pre[r ] != r )
          r=pre[r ];

    int i=x , j ;
    while( i != r )
    {
         j = pre[ i ];
         pre[ i ]= r ;
         i=j;
    }
    return r ;
}


void join(int x,int y)
{
    int fx=fin(x),fy=fin(y);
    if(fx!=fy){
        if(fx>fy){
            pre[fx]=fy;
        }
        else{
            pre[fy]=fx;
        }
    }
}
int main(){
    int i;
    for(i=1;i<=100;i++){
        pre[i]=i;
    }
    int n,m,k;
    cin>>n>>m>>k;
    for(i=0;i<m;i++){
        int a,b,r;
        cin>>a>>b>>r;
        if(r==1){
            join(a,b);
        }
        else{
            envy[a][b]=1;
            envy[b][a]=1;
        }
    }
    for(i=0;i<k;i++){
        int a,b;
        cin>>a>>b;
        int fri;
        int ene;
        if(fin(a)==fin(b)){
            fri=1;
        }
        else{
            fri=0;
        }
        if(envy[a][b]){
            ene=1;
        }
        else{
            ene=0;
        }
        if(fri==1&&ene==0){
            cout<<"No problem"<<endl;
        }
        else if(fri==1&&ene==1){
            cout<<"OK but..."<<endl;
        }
        else if(fri==0&&ene==0){
            cout<<"OK"<<endl;
        }
        else if(fri==0&&ene==1){
            cout<<"No way"<<endl;
        }
    }
}
