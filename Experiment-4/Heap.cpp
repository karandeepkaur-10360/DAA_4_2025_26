#include<bits/stdc++.h>

using namespace std;
#define MAX 100

int heap[MAX];
int heapSize=0;


void heapifyDown(int i ) {
    int small = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left<heapSize && heap[left]<heap[small]){
        small = left;
        }
    if(right <heapSize && heap[right]<heap[small]){
            small = right;
        }
    if(i!=small) {
        swap(heap[i] , heap[small]);
        heapifyDown(small);
        }
}
void heapifyUp(int i) {
        while(i>0 && heap[(i-1)/2] > heap[i]) {
            swap(heap[(i-1)/2], heap[i]);
            i = (i-1)/2;
                }

}
void insert(int val) {

    if(heapSize == MAX){
        cout<<"Heap is full";
        return;
}
    heap[heapSize] = val;
    heapSize++;
    heapifyUp(heapSize-1);
}
void deleteRoot() {

if(heapSize==0) {
cout<<"underflow" ;
return ;
}
heap[0] = heap[heapSize-1];
heapSize--;
heapifyDown(0);

}

void deletebyvalue(int val) {

    if(heapSize==0) {
        cout<<"Heap is Empty" ;
        return ;
}
    int indx=-1;
    for(int i=0;i<heapSize;i++){
        if(heap[i]==val){
            indx=i;
            break;
        }
    }
    if(indx==-1){
        
      cout<<"Element to be deleted is not found" << endl;
      return ;}
    heap[indx] = heap[heapSize - 1];
    heapSize--;

    
    heapifyDown(indx);
    heapifyUp(indx);
}
int search(int heap[], int heapSize, int val){
 for(int i=0;i<heapSize;i++){
 if (heap[i]==val){
  return i;}}

return -1 ;}
int main() {

insert(1);
insert(5);
insert(9);
insert(12);
insert(20);
insert(27);
deletebyvalue(9);
cout<<"Final heap : "<<endl;
for(int i =0;i<heapSize;i++) cout<<heap[i]<< " ";
    int key = 12;
 int result = search(heap,heapSize,key);
    if(result!=-1){
        cout<<"Element found at index : "<< result<<endl;}
    else{
        cout<<"Element not found" <<endl;}
  return 0;
}


