#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
#define maxn 1001
vector<int> nums(maxn);
int visited[10];
int idx[10];
int cnt = 0;
void arrange(vector<int> &num, int n)
{ // 数组索引从i到j
    if (n == cnt)
    {
        for (int j = 0;j < cnt;j++)
        {
            cout << num[idx[j]] << " ";
        }
        cout << endl;
        return;
    }
    else
    {
        for (int i = 0; i < cnt ;i++)
        {
            if(visited[i] == 0){
                visited[i] = 1;
                idx[n] = i;
                arrange(nums,n+1);
                visited[i] = 0;
            }
        }
    }
}
int main()
{
    ifstream in("in.txt");
    string line;
    int nn;
    while (getline(in, line))
    {
        cnt = 0;
        nums.clear();
        stringstream ss(line);
        while (ss >> nn)
        {
            cnt++;
            nums.push_back(nn);
        }
        arrange(nums, 0);
    }
    return 0;
}