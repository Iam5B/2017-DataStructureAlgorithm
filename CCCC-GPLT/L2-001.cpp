#include<iostream>
#include<stack>
using namespace std;
typedef struct{
    int value;
    int distance;
}e;
int setnum=0;
int status[500]={0};
int valroot[500][500]={0};
int start;
int target;
e point[500];
int citynum,rootnum;
void spread(int s){
    int i;
    for(i=0;i<citynum;i++){
        if(valroot[s][i]&&point[i].distance>valroot[s][i]+point[s].distance){
            point[i].distance=valroot[s][i]+point[s].distance;
        }
    }
    return;
}

int expand(){
    int choose=-1;
    int distance;
    int i;
    for(i=0;i<citynum;i++){
        if(choose==-1&&status[i]==0&&point[i].distance!=10000){
            choose=i;
            distance=point[i].distance;
        }
        if(status[i]==0&&point[i].distance<distance){
            choose=i;
            distance=point[i].distance;
        }
    }
    status[choose]=1;
    setnum++;
    return choose;
}

int root[500];
int rootlen=0;
int bestroot[500];
int bestrootlen;
int maxval=0;
int roots=0;

void dfs(int p,int dis,int val){
    /*cout<<"p:"<<p<<" dis:"<<dis<<" val:"<<val<<endl;*/

    if(p==start&&val>maxval){
        maxval=val;
        int i;
        for(i=0;i<rootlen;i++){
            bestroot[i]=root[i];
        }
        bestrootlen=rootlen;
        roots++;
        return;
    }
    if(p==start){
        roots++;
        return;
    }
    int i;
    for(i=0;i<citynum;i++){
        if(valroot[i][p]&&point[i].distance+valroot[i][p]==dis){
            root[rootlen++]=i;
            dfs(i,point[i].distance,val+point[i].value);
            rootlen--;
        }
    }
}

int main(){

    cin>>citynum>>rootnum>>start>>target;
    int i;
    for(i=0;i<citynum;i++){
        int val;
        cin>>val;
        point[i].value=val;
        point[i].distance=10000;
    }
    for(i=0;i<rootnum;i++){
        int x,y,z;
        cin>>x>>y>>z;
        valroot[x][y]=valroot[y][x]=z;
    }
    point[start].distance=0;
    setnum=1;
    status[start]=1;
    spread(start);
    while(setnum!=citynum){
        int s = expand();
        spread(s);
    }
    /*for(i=0;i<citynum;i++){
        cout<<i<<":"<<point[i].distance<<endl;
    }*/

    root[rootlen++]=target;
    dfs(target,point[target].distance,point[target].value);
    /*stack<int> root;
    root.push(target);
    int p;
    p=point[target].frm;
    while(p!=start){
        root.push(p);
        p=point[p].frm;
    }
    root.push(p);
    cout<<point[target].frms<<" "<<point[target].maxvalue<<endl;
    int ctr;
    ctr=0;
    while(!root.empty()){
        int t;
        if(ctr)cout<<" ";
        ctr++;
        cout<<root.top();
        root.pop();
    }
    cout<<endl;
    */
    cout<<roots<<" "<<maxval<<endl;
    for(i=bestrootlen-1;i>=0;i--){
        if(i!=0)
            cout<<bestroot[i]<<" ";
        else
            cout<<bestroot[i]<<endl;
    }
    return 0;
}
