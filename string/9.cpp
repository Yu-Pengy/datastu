#include<iostream>
#include<cstring>
using namespace std;
int getLength(char *p){
    return strlen(p);
}
void getNextval(char *s,int *nextval){
    int i = 0,k = -1;
    nextval[0] = -1;
    int slen = getLength(s);
    while(i < slen){
        if(k == -1 || s[i] == s[k]){
            i++;
            k++;
            if(s[i] != s[k])nextval[i] = k;
            else nextval[i] = nextval[k];
        }
        else k = nextval[k];
    }
}
int KMP(char *s,char *t){
    int m = getLength(s);
    int n = getLength(t);
    cout << m << " " << n << endl;
    int rnt = -1;
    int *nextval = new int[n];
    getNextval(t,nextval);
    int i = 0;int j = 0;
    while(i < m){
        if(j == -1 || s[i] == t[j]){
            i++;
            j++;
            if(j == n){
                rnt = i - n;
            }
        }
        else j = nextval[j];
    }
    return rnt;
}
int main(){
    char s[100];
    char t[100];
    cin.getline(s,100);
    //cin.ignore();
    cin.getline(t,100);
    cout << KMP(s,t) << endl;
}