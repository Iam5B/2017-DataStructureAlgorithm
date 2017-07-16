#include<iostream>
using namespace std;

void print(int a){
    int b;
    b=a;
    int blanks;
    blanks=5;
    if(a<0){
        blanks-=1;
        a=0-a;
    }
    do{
        blanks--;
        a/=10;

    }while(a);
    int i;
    for(i=0;i<blanks;i++){
        cout<<" ";
    }
    cout<<b;
}

int main(){
    int frm;
    int to;
    while(cin>>frm>>to){
        int sum;
        sum=0;
        int cnt=1;
        for(;frm<=to;cnt++,frm++){
            sum+=frm;
            print(frm);
            if(cnt%5==0){
                cout<<endl;
            }

        }

        if((cnt-1)%5!=0){
            cout<<endl;
        }
        cout<<"Sum = "<<sum<<endl;
    }
    return 0;
}
