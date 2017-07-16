#include<iostream>
using namespace std;
int pre[100000];
int exist[100000]={0};
int group=0;
int root[100000]={0};
int people=0;
int fin(int x)
{
    int r=x;
    while ( pre[r] != r )
          r=pre[r];

    int i=x , j ;
    while( i != r )
    {
         j = pre[i];
         pre[i]= r ;
         i=j;
    }
    return r ;
}


void join(int x,int y)
{
    int fx=fin(x),fy=fin(y);
    if(fx!=fy)
        pre[fx]=fy;
}

int main(){
    int n;
    cin>>n;
    int i;
    for(i=0;i<10000;i++)pre[i]=i;
    for(i=0;i<n;i++){
        int m;
        cin>>m;
        int j;
        int lead;
        for(j=0;j<m;j++){
            int temp;
            cin>>temp;
            if(!j)
                lead=temp;
            else
                join(temp,lead);
            if(!exist[temp]){
                exist[temp]=1;
                people++;
            }
        }
    }
    cout<<people<<" ";
    for(i=1;i<=people;i++){
        if(!root[fin(i)]){
            root[fin(i)]=1;
            group++;
        }
    }
    cout<<group<<endl;
    cin>>n;
    for(i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        if(fin(x)==fin(y)){
            cout<<"Y"<<endl;
        }
        else{
            cout<<"N"<<endl;
        }
    }
    return 0;
}
