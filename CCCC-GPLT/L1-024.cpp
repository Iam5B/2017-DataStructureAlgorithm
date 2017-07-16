#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int judge(string str){
    if(str.size()==0){
        return 0;
    }
    if(str[0]=='0'){
        return 0;
    }
    int i;
    int tar;
    tar=0;
    for(i=0;i<str.size();i++){
        if(str[i]>='0'&&str[i]<='9'){
            tar*=10;
            tar+=(int)(str[i]-'0');
        }
        else{
            return 0;
        }
    }
    if(tar>1000)return 0;
    return tar;
}

int main(){
    string all;
    getline(cin,all);
    int i;
    string t1,t2;
    t1="";
    t2="";
    for(i=0;all[i]!=' ';i++){
        t1+=all[i];
    }
    i++;
    for(;i<all.size();i++){
        t2+=all[i];
    }

        int flag1,flag2;
        flag1=0;
        flag2=0;
        flag1=judge(t1);
        flag2=judge(t2);
        if(flag1){
            cout<<flag1;
        }
        else{
            cout<<"?";
        }
        cout<<" + ";
        if(flag2){
            cout<<flag2;
        }
        else{
            cout<<"?";
        }
        cout<<" = ";
        if(flag1*flag2){
            cout<<flag1+flag2;
        }
        else{
            cout<<"?";
        }
        cout<<endl;
    return 0;
}
