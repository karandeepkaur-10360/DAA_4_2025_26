#include <bits/stdc++.h>
using namespace std;
int main(){
    int K;
    int N;
    cin>>K;
    cin>>N;
    vector<int> arr(N);
    
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    
    for(int i = 0; i < N; i++) {
        cin>>arr[i];
        if(pq.size() < K) {
            pq.push(arr[i]);
        }
        else if(arr[i] > pq.top()) {
            pq.pop();
            pq.push(arr[i]);
        }

        if(pq.size() < K)
            cout << -1 << endl;
        else
            cout << pq.top() << endl;
    }

    return 0;
}

