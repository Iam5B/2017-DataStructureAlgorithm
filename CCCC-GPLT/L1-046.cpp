#include<iostream>
#include<queue>
using namespace std;
long long toint(string t){
    long long tar;
    tar = 0;
    int i;
    for(i=0;i<t.size();i++){
        tar*=10;
        tar+=t[i]-'0';
    }
    return tar;
}

string revert(string t){
    string tar;
    tar="";
    int i;
    i=t.size()-1;
    for(;i>=0;i--){
        tar+=t[i];
    }
    return tar;
}
string adjust(string t){
    if(t.size()==10){
        return t;
    }
    else{
        int bu;
        bu=10-t.size();
        string tar;
        tar="";
        int i;
        for(i=0;i<bu;i++){
            tar+="0";
        }
        tar+=t;
        return tar;
    }
}
string tostr(long long t){
    string tar;
    tar="";
    while(t){
        tar+=(char)(t%10+'0');
        t/=10;
    }
    return revert(tar);
}
int mod(string beichu,string chu,string &result){
    long long chu1;
    chu1=toint(chu);
    queue<long long> numque;
    int len = beichu.size();
    if(len<=10){
        numque.push(toint(beichu));
    }
    else if(len>10){
        int firstlength=10+len%10;
        int left = (len-10-len%10)/10;
        int i;
        string temp;
        temp="";
        for(i=0;i<len;i++){
            int nowlen;
            nowlen=i+1;
            temp+=beichu[i];
            if(nowlen==firstlength){
                numque.push(toint(temp));
                temp="";
            }
            else if((nowlen-firstlength)%10==0&&nowlen>firstlength){
                numque.push(toint(temp));
                temp="";
            }
        }
    }
    result = "";
    long long prev;
    prev = 0;
    int ctr;
    ctr=0;
    while(!numque.empty()){
        long long te;
        te=numque.front();
        numque.pop();
        te=te+prev*10000000000;
        if(ctr)
            result+=adjust(tostr(te/chu1));
        else
            result+=tostr(te/chu1);
        ctr++;
        prev = te%chu1;
        if(numque.empty()){
            if(prev==0){
                return 1;
            }
            else{
                return 0;
            }
        }
    }
}
int main(){
    string beichu;
    int ctr;
    ctr=1;
    beichu="1";
    string chu;
    string result;

        cin>>chu;
        while(!mod(beichu,chu,result)){
            beichu+="1";
            ctr++;
        }
        cout<<result<<" "<<ctr<<endl;

    return 0;
}
