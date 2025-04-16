#include <iostream>
using namespace std;
void getNext(string t, int *next)
{
    int i = 0, k = -1;
    next[0] = -1;
    while (i < t.length() - 1)
    { // 防止数组溢出
        if (k == -1 || t[i] == t[k])
        {
            i++;
            k++;
            next[i] = k;
        }
        else
            k = next[k];
    }
}
void getNextval(string t, int *nextval)
{
    int i = 0, k = -1;
    nextval[0] = -1;
    while (i < t.length() - 1)
    {
        if (k == -1 || t[i] == t[k])
        {
            i++;
            k++;
            if (t[i] == t[k])
                nextval[i] = nextval[k];
            else
                nextval[i] = k;
        }
        else
            k = nextval[k];
    }
}
int KMP(string s, string t)
{
    int n = s.length();
    int m = t.length();
    int *next = new int[m];
    int i = 0, j = 0;
    getNextval(t, next);
    while (i < n && j < m)
    {
        if (j == -1 || s[i] == t[j])
        {
            i++;
            j++;
        }
        else
            j = next[j];
    }
    if (j >= m)
        return i - m;
    else
        return -1;
}
int main(){
    string s1 = "ababcdacd";
    string s2 = "acd";
    cout << KMP(s1,s2) << endl;
}