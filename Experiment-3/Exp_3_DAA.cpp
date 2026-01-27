
#include <bits/stdc++.h>

using namespace std;
int main(){
    int N;
    cin>>N;
    cin.ignore();
    
    unordered_map<int,int> m;
    int sum=0;
    int maxsize=0;
    char c;
    m[0]=-1;
    
    for(int i=0 ; i<N;i++){
        
        cin>> c;
        
        if(c=='A'){
            sum=sum-1;
        }
        else{
            sum=sum+1;
        }
        
        if(m.find(sum)!=m.end()){
            maxsize=max(maxsize,i-m[sum]);
        }
        else{
            m[sum]=i;
        }
    }
    cout<<maxsize;
    return 0;
}