#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

    bool isPossible(vector<int>& arr, int k, long long mid) {
        int painters = 1;
        long long time = 0;

        for (int length : arr) {
            if (length > mid) return false; 

            if (time + length > mid) {
                painters++;
                time = length;  
            } else {
                time += length;
            }
        }

        return painters <= k;
    }

    int minTime(vector<int>& arr, int k) {
        long long low = *max_element(arr.begin(), arr.end()); 
        long long high = accumulate(arr.begin(), arr.end(), 0LL); 
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (isPossible(arr, k, mid)) {
                ans = mid;        
                high = mid - 1;
            } else {
                low = mid + 1;    
            }
        }

        return ans;
    }
};
