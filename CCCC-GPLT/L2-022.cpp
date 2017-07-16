#include<iostream>
#include<iomanip>
using namespace std;
int lisarr[100001][4]={0};
int main(){
    int start;
    int n;
    cin>>start>>n;
    int i;
    int address;
    int val;
    int next;
    int lastadd;
    for(i=0;i<n;i++){
        cin>>address>>val>>next;
        lisarr[address][1]=val;
        lisarr[address][2]=next;
        lisarr[next][0]=address;
        if(next==-1){
            lastadd=address;
        }
    }
    int ctr=n;
    while(1){

        if(!lisarr[lastadd][3]){
            cout<<setw(5)<<setfill('0')<<lastadd<<" "<<lisarr[lastadd][1];
            if(!(ctr-1)){
                cout<<" "<<-1<<endl;
                break;
            }
            else{
                cout<<" "<<setw(5)<<setfill('0')<<start<<endl;
            }
            lisarr[lastadd][3]++;
            lastadd=lisarr[lastadd][0];
            ctr--;
        }
        else{
            break;
        }
        if(!lisarr[start][3]){
            cout<<setw(5)<<setfill('0')<<start<<" "<<lisarr[start][1];
            if(!(ctr-1)){
                cout<<" "<<-1<<endl;
                break;
            }
            else{
                cout<<" "<<setw(5)<<setfill('0')<<lastadd<<endl;
            }
            lisarr[start][3]++;
            start=lisarr[start][2];
            ctr--;
        }
        else{
            break;
        }
    }
    return 0;
}
