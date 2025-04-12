#include<iostream>
using namespace std;
int findidx(string s,int i,int &idx,char c){
    if(i > s.size() - 1){
        if(idx == -1) return -1;
        else return idx;
    }
    if(s[i] == c)idx = i;
    return findidx(s,i+1,idx,c);
}
int main(){
    int idx = -1;
    string s = "abcdc";
    cout << findidx(s,0,idx,'c');
    return 0;
}