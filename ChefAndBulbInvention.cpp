#include<iostream>
#include<map>
using namespace std;

int main(){

    int testcases;
    cin>>testcases;

    for(int i=0;i<testcases;i++){
        int n,p,k;
        cin>>n>>p>>k;
        int mod=0;
        int *pointer=new int[n];
        int arrIndex=0;
        int flag=0;
        for(int index=0;index<n;index++){
            for(int j=index;j<n&&mod<=k;j++){
                if(j%k==mod){
                    
                    if(p==j){
                        flag=1;
                        break;
                    }
                    arrIndex++;
                }
            }
            if(flag==1){
                break;
            }
            mod++;
        }
        cout<<arrIndex+1<<endl;
        delete [] pointer;
        pointer=nullptr;
    }

    return 0;
}