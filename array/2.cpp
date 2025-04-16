#include<iostream>
using namespace std;
int findidx(int *arr,int size){
    int min = 1000001;int idx = -1;
    for(int i = 0;i < size;i++){
        if(arr[i] <= min){
            idx = i;
            min = arr[i];
        }
    }
    return idx;
}
int main(){
    int a[] = {1,2,3,1,5};
    cout << findidx(a,5) << endl;
}