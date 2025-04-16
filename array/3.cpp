#include<iostream>
using namespace std;
int main(){
    double a[] = {1,2,3,4,5};
    int b[] = {2,3,4,0,1};
    int c[5] = {0};
    for(int i = 0;i < 5;i++){
        //int temp = a[i];
        c[i] = a[b[i]];
        //a[b[i]] = temp;
        
    }
    for(int i = 0;i< 5;i++){
        cout << c[i] << " ";
    }
    cout << endl;
}