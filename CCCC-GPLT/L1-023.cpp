#include<iostream>
using namespace std;
int main(){
  int n;
  while(cin>>n){
  cout<<(((n+2)>7)?(n+2):(n+2)%7)<<endl;
  }
  return 0;
}
