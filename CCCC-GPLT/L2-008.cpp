#include<iostream>
using namespace std;
string t;
int leng;
int checks(int a){
    int len=-1;
    int iplus=a;
    int iminus=a;
    for(;iplus<leng&&iminus>=0&&t[iplus]==t[iminus];iplus++,iminus--,len+=2);
    return len;
}
int checkd(int a,int b){
    int len=0;
    int iminus=a;
    int iplus=b;
    for(;iplus<leng&&iminus>=0&&t[iplus]==t[iminus];iplus++,iminus--,len+=2);
    return len;
}
int maxx=0;
int main(){
    getline(cin,t);
    int i;
    leng = t.size();
    for(i=0;i<leng;i++){
        int a = checks(i);
        int b = 0;
        if(i+1<=leng-1)
            b = checkd(i,i+1);
        if(a>maxx){
            maxx=a;
        }
        if(b>maxx){
            maxx=b;
        }
    }
    cout<<maxx<<endl;
}
