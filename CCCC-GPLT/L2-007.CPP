#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int Prev[10000];
int fin(int x)
{
    int r=x;
    while(Prev[r] != r )
          r=Prev[r];

    int i=x , j ;
    while(i != r )
    {
         j = Prev[ i ];
         Prev[i]= r ;
         i=j;
    }
    return r ;
}

void join(int x,int y)                                                                                                                                                                                      //如果已经连通，就不用管了 //如果不连通，就把它们所在的连通分支合并起,
{
    int fx=fin(x),fy=fin(y);
    if(fx>fy){
        Prev[fx]=fy;
    }
    else{
        Prev[fy]=fx;
    }
}

int total[10000][4]={0};
int arr[10000][3]={0};
typedef struct N{
    int id;
    int people;
    double aves;
    double avet;
}Node;
int fun(Node a,Node b){
    if(a.aves>b.aves){
        return 1;
    }
    if(a.aves==b.aves){
        return a.id<b.id;
    }
    else{
        return 0;
    }
}
int main(){
    int i;
    for(i=0;i<10000;i++)Prev[i]=i;
    int n;
    cin>>n;
    for(i=0;i<n;i++){
        int id;
        int par1;
        int par2;
        int m;
        cin>>id>>par1>>par2>>m;
        if(par1!=-1){
            join(id,par1);
            arr[par1][0]=1;
        }
        if(par2!=-1){
            join(id,par2);
            arr[par2][0]=1;
        }
        int j;
        for(j=0;j<m;j++){
            int temp;
            cin>>temp;
            join(id,temp);
            arr[temp][0]=1;
        }
        int tao,square;
        cin>>tao>>square;
        arr[id][0]=1;
        arr[id][1]=tao;
        arr[id][2]=square;
    }
    for(i=0;i<10000;i++){
        if(arr[i][0]){
            int tar = fin(i);
            total[tar][0]=1;
            total[tar][1]+=arr[i][1];
            total[tar][2]+=arr[i][2];
            total[tar][3]++;
        }
    }
    Node result[1000];
    int rp=0;
    /*Node result[1000];
        int id;
        int people;
        double aves;
        double avet;
    }Node;*/

    for(i=0;i<10000;i++){
        if(total[i][0]){
            int ta = total[i][1];
            int sq = total[i][2];
            int nu = total[i][3];
            //cout<<ta<<" "<<sq<<" "<<nu<<" "<<endl;
            result[rp].id=i;
            result[rp].people=nu;
            result[rp].aves=((double)sq)/((double)nu);
            result[rp++].avet=((double)ta)/((double)nu);
        }
    }
    sort(result,result+rp,fun);
    cout<<rp<<endl;
    for(i=0;i<rp;i++){
        cout<<setw(4)<<setfill('0')<<result[i].id<<" "<<result[i].people<<" "<<fixed<<setprecision(3)<<result[i].avet<<" "<<result[i].aves<<endl;
        cout.unsetf(ios_base::fixed);
    }
    return 0;
}
