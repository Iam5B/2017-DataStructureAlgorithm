#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int heap[1000]={0};
int heapn=0;
int indexOf(int k){
    int i;
    for(i=0;i<heapn;i++){
        if(k==heap[i]){
            return (i+1);
        }
    }
    return 0;
}
int HeapInsert(int *heap,int &n,int num){
	int i,j;
	heap[n] = num;
	i = n;
	j = (n - 1) / 2;

	while(j >= 0 && i != 0){
		if(heap[j] <= num){
			break;
		}
		heap[i] = heap[j];
		i = j;
		j = (i - 1) / 2;
	}
	heap[i] = num;
	n++;
	return 0;
}
int main(){
    int n,m;
    cin>>n>>m;
    int i;
    for(i=0;i<n;i++){
        int temp;
        cin>>temp;
        HeapInsert(heap,heapn,temp);
    }
    /*for(i=0;i<n;i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;*/
    for(i=0;i<m;i++){
        string t;
        int tar1;
        int tar2;
        cin>>tar1>>t;
        if(!t.compare("is")){
            cin>>t;
            if(!t.compare("the")){
                cin>>t;
                if(!t.compare("root")){
                    //is root of
                    int temp = indexOf(tar1);
                    if(temp==1){
                        cout<<"T"<<endl;
                    }
                    else{
                        cout<<"F"<<endl;
                    }
                }
                else{
                    //is parent
                    cin>>t;
                    cin>>tar2;
                    int temp1,temp2;
                    temp1=indexOf(tar1);
                    temp2=indexOf(tar2);
                    if(temp1==temp2/2){
                        cout<<"T"<<endl;
                    }
                    else{
                        cout<<"F"<<endl;
                    }
                }
            }
            else{
                cin>>t;
                // is a child
                cin>>t;
                    cin>>tar2;
                    int temp1,temp2;
                    temp1=indexOf(tar1);
                    temp2=indexOf(tar2);
                    if(temp1/2==temp2){
                        cout<<"T"<<endl;
                    }
                    else{
                        cout<<"F"<<endl;
                    }
            }
        }
        else{
            // are siblings
            cin>>tar2>>t>>t;
            int temp1,temp2;
            temp1=indexOf(tar1);
            temp2=indexOf(tar2);
            if(temp1>temp2){
                int qure;
                qure=temp1;
                temp1=temp2;
                temp2=qure;
            }
            if((temp2%2)&&((temp1+1)==temp2)){
                cout<<"T"<<endl;
            }
            else{
                cout<<"F"<<endl;
            }
        }
    }
    return 0;
}
