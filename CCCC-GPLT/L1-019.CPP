#include<iostream>
using namespace std;
int main(){
    int maxA,maxB;
    while(cin>>maxA>>maxB){
        int n;
        cin>>n;
        int i;
        int A,B;
            A=0;
            B=0;
        int mute=0;
        for(i=0;i<n;i++){

            int As,Ah,Bs,Bh;
            cin>>As>>Ah>>Bs>>Bh;
            int flagA,flagB;
            flagA=0;
            flagB=0;
            if(Ah==As+Bs){
                flagA=1;
            }
            if(Bh==As+Bs){
                flagB=1;
            }
            if(flagA*flagB==0&&flagA+flagB==1){
                A+=flagA;
                B+=flagB;
            }
            if(A>maxA&&!mute){
                cout<<"A"<<endl<<B<<endl;
                mute=1;
            }
            else if(B>maxB&&!mute){
                cout<<"B"<<endl<<A<<endl;
                mute=1;
            }

        }
    }
    return 0;
}
