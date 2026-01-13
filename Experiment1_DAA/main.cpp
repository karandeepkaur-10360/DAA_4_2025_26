#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
int count=0;
void complexRec(int n) {
     count=count++;

   if (n <= 2) {
       return;
   }


   int p = n;
   while (p > 0) {
       vector<int> temp(n);
       for (int i = 0; i < n; i++) {
           temp[i] = i ^ p;
       }
       p >>= 1;
       
   }


   vector<int> small(n);
   for (int i = 0; i < n; i++) {
       small[i] = i * i;
   }


   if (n % 3 == 0) {
       reverse(small.begin(), small.end());
   } else {
       reverse(small.begin(), small.end());
   }


   complexRec(n / 2);
   complexRec(n / 2);
   complexRec(n / 2);
   
}
// The recurence relation for the above code will be T(n)=3T(n/2)+nlogn+3n/2 
//and we can ignore the 3n/2 term as its less than nlogn 
// we got 3T(n/2) from three recurrence calls of function and for while loop we got nlogn , for another for loop we got n and for reverse we got n/2 
// Thus the final recurrence relation we got is T(n)=3T(n/2)+nlogn
// We can solve this reccurence relation by Case : a<b^k of Master Method
// as a=3,b=2,k=1,p=1 we got Time Complexity of O(n^log base 2 power 3)

int main(){
    auto start =high_resolution_clock::now();
    
    
    cout<<"Number of operations :"<<count<<endl;
    
    complexRec(n);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast< milliseconds > (end-start);
    cout<<"Time taken :"
    cout<<duration.count();
    
    
    
}
