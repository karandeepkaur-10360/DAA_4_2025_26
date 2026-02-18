#include <bits/stdc++.h>
using namespace std;
int lowerbound(vector<int> arr,int element){
    int l=0;
    int r=arr.size()-1;
   int ans = arr.size();
    while(l<=r){
        int mid = (l+r)/2;
        if(arr[mid]>=element){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    } return ans;
}

int upperbound(vector<int> arr, int element){
    int l=0;
    int r=arr.size()-1;
   int ans = arr.size();
    while(l<=r){
        int mid = (l+r)/2;
        if(arr[mid]>element){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    } return ans;
}
    
int main(){
    vector<int> arr={4,5,6,7,12,14};

    int element;
    cin>>element;

    cout<<"Lower-Bound of "<<element <<" is "<<lowerbound(arr,element)<<endl;
    cout<<"Upper-Bound of "<<element <<" is "<<upperbound(arr,element)<<endl;


    return 0;
}
