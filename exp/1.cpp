#include <iostream>
#include <string>
using namespace std;
bool isgoodbot(const string &s, int ini, int end)
{
    if (ini == end)
        return true;
    for (int i = ini; i <= end - 1; i++)
    {
        if ((s[i + 1] - s[i]) != 1 && (s[i + 1] != s[i]))
            return false;
    }
    return true;
}
bool isgood(const string &s)
{
    bool ret = false;
    bool before = false, curr = false;
    if(s.size() == 2)return true;
    for (int i = 0; i < s.size(); i++)
    {
        curr = (isgoodbot(s, 0, i) && isgoodbot(s, i + 1, s.size() - 1));
        ret = before || curr || ret;
        before = curr;
    }
    return ret;
}

int main()
{
    string s;
    cin >> s;
    int n = s.length();
    int cnt = 0;
    for (int length = 1; length <= n; length++)
    {
        for (int start = 0; start <= n - length; ++start)
        {
            if (isgood(s.substr(start, length))) cnt++;
        }
    }
    cout << cnt << endl;
}