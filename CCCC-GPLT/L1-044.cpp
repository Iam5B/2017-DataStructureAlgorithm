#include<iostream>
using namespace std;
string win(string t){
  if((t[0]=='J')){
	return "ChuiZi";
  }
  if((t[0]=='C')){
  	return "Bu";
  }
  if((t[0]=='B')){
  	return "JianDao";
  }
}
string tie(string t){
  return t;
}

int main(){
  int n;
  cin>>n;
  int ctr;
  n++;
  ctr=1;
  string t;
  cin>>t;
  while(t[0]!='E'){
    if(ctr%n==0){
      cout<<tie(t);
    }
    else{
      cout<<win(t);
    }
    cout<<endl;
    ctr++;
    cin>>t;
  }
  return 0;
}
