#include<iostream>
#include<string>
using namespace std;
string reverse(string s){
    if(s.size() <= 1) return s;
    else return reverse(s.substr(1)) + s[0];
}
int main(){
    string ss = "123456";
    cout << reverse(ss);
    //cout << ss << endl;
}
//substr,返回一个子字符串，第一个参数是起始索引，第二个参数是长度，如果不指定第二个参数，默认到末尾