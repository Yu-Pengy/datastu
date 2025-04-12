#include<iostream>
using namespace std;
int findmax(int *a,int i,int j){
    if((j - i) == 0) return a[i];
    int mid = (j + i)/2;
    return max(findmax(a,i,mid),findmax(a,mid + 1,j));//注意两部分不重叠 //把大问题化为小问题
}
int main(){
    int a[] = {3,5,66,3,2,4,5,5,66,67};
    cout << findmax(a,0,9) << endl;
}