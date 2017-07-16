#include<iostream>
#include<stack>
using namespace std;

int pre[500];
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
int rebuild[500]={0};
int rp=0;

void join(int x,int y)
{
    int fx=fin(x),fy=fin(y);
    if(fx!=fy)
        pre[fx]=fy;
}
stack<int> res;
int arr[500][500]={0};
int attack[500]={0};
int n,m;
void append(int a){
    int i;
    for(i=0;i<n;i++){
        if(arr[i][a]&&rebuild[a]&&rebuild[i]){
            join(i,a);
        }
    }
}
int Count(){
    int i;
    int ar[500]={0};
    int cnt=0;
    for(i=0;i<n;i++){
        if(ar[fin(i)]){
            continue;
        }
        else{
            ar[fin(i)]=1;
            cnt++;
        }
    }
    return cnt;
}
void print(){
    while(!res.empty()){
        int t=res.top();
        res.pop();
        if(t==-1){
            cout<<"Red Alert: ";
            t=res.top();
            res.pop();
            cout<<"City "<<t<<" is lost!"<<endl;
        }
        else{
            cout<<"City "<<t<<" is lost."<<endl;
        }
    }
}
int main(){

    cin>>n>>m;
    int i;
    for(i=0;i<n;i++){
        pre[i]=i;
    }
    for(i=0;i<m;i++){

        int x,y;
        cin>>x>>y;
        arr[x][y]=arr[y][x]=1;
    }
    cin>>m;
    int des[500]={0};
    for(i=0;i<m;i++){
        cin>>attack[i];
        des[attack[i]]=1;
    }
    for(i=0;i<n;i++){
        if(!des[i]){
            rebuild[i]=1;
            append(i);
        }
    }
    int j;
    int fz=Count();
    for(j=m-1;j>=0;j--){
        rebuild[attack[j]]=1;
        res.push(attack[j]);
        append(attack[j]);
        int temp = Count();
        cout<<"rebuild "<<attack[j]<<" there are "<<temp<<" branch"<<endl;
        if(temp<fz-1){
            fz=temp;
            res.push(-1);
        }
        fz=temp;
    }
    print();
    if(n==m)
        cout<<"Game Over."<<endl;
}
