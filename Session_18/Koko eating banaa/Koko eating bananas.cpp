class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*max_element(piles.begin(),piles.end());
        int ans=r;
        while(l<=r){
            int mid=(l+r)/2;
            if(ispos(piles,mid,h)){
                ans=mid;
                r=mid-1;
            } 
            else{
                l=mid+1;
            } 
        }return ans;
    }

bool ispos(vector<int> &piles,int k , int h ){
    long long cnt=0;
     for (int bananas : piles) {
            cnt += (bananas + k - 1) / k;   
        }
        return cnt<= h;
}


    
};