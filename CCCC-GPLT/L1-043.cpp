#include<iostream>
using namespace std;
typedef struct {
    int status;
    string timememory;
}book;
book arr[1001];
void clearstatus(){
    int i;
    for(i=0;i<1001;i++){
        arr[i].status=0;
        arr[i].timememory="";
    }
    return;
}

int strminus(string a,string b){
    return (( (a[0]-'0')*10 + (a[1]-'0') )*60 + (a[3]-'0')*10 + (a[4]-'0'))-(( (b[0]-'0')*10 + (b[1]-'0') )*60 + (b[3]-'0')*10 + (b[4]-'0'));
}

int main(){

    int n;
    cin>>n;
    int i;
    for(i=0;i<n;i++){
        clearstatus();
        int num;
        char mode;
        string tim;
        int borrortime;
        int timesum;
        borrortime = timesum = 0;
        cin>>num>>mode>>tim;
        int sumtime;
        int sumreader;
        sumtime=0;
        sumreader=0;
        while(num!=0){
            if(arr[num].status==0&&mode=='S'){
                arr[num].status=1;
                arr[num].timememory=tim;
            }
            else if(arr[num].status==0&&mode=='E'){
                cin>>num>>mode>>tim;
                continue;
            }
            else if(arr[num].status==1&&mode=='S'){
                arr[num].status=1;
                arr[num].timememory=tim;
            }
            else if(arr[num].status==1&&mode=='E'){
                arr[num].status=0;
                sumtime+=strminus(tim,arr[num].timememory);
                sumreader++;
            }
            cin>>num>>mode>>tim;
        }
        if(sumreader==0){
            cout<<0<<" "<<0<<endl;
        }
        else{
            cout<<sumreader<<" "<<(int)((double)sumtime/(double)sumreader+0.5)<<endl;
        }

    }
    return 0;

}
