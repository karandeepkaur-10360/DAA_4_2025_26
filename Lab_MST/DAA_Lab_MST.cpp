class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        vector <int> maxArr;
        if(k==1) return arr;
        for(int i=0;i<=n-k;i++){
            int maxElement=arr[i];
            for(int j=i;j<i+k;j++){
                if(arr[j]>maxElement){
                    maxElement=arr[j];
                }
            }
             maxArr.push_back(maxElement); 
        } 
       
        return maxArr;
    }
};