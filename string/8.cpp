#include<iostream>
#include<cstring>
using namespace std;
int getLength(char *p){
    return strlen(p);
}
int BF(char *s,char *t){
    int i = 0,j = 0,cnt = 0;
    int slen = getLength(s);
    int tlen = getLength(t);
    while(i < slen){
        if(s[i] = t[j]){
            i++;
            j++;
        }
        if(j == tlen){
            j = 0;
            cnt++;
        }
    }
    return cnt;
}
int main(){
    char s[100];
    char t[100];
    cin.getline(s, 100);
    cin.ignore();
    cin.getline(t,100);
    cout << BF(s,t) << endl;
    return 0;

}

    
