#include <iostream>
#include <fstream>
using namespace std;
#define maxn 101
int n; // 共有n个皇后
int cnt = 0;
int q[maxn];//queen记录自身的列数
bool canput(int i, int j)
{ // 判断(i,j)能否放置皇后
    if(i == 0)return true;
    int k = 0;
    while(k < i){
        if(q[k] == j || abs(j - q[k]) == abs(i - k)) return false;
        k++;
    }
    return true;
}
void totalNQueens(int i, int n)
{ // 放置第i行的皇后
    if (i >= n){//回溯条件
        cnt++;
        return;
    }
    else
    {
        for (int j = 0; j < n; j++)
        {
            if (canput(i, j))
            {
                q[i] = j;
                totalNQueens(i + 1, n);
            }
        }
    }
}
int main(){
    ifstream in("in.txt");
    int n;
    while(in >> n){
        totalNQueens(0,n);
        cout << cnt << endl;
        cnt = 0;
    }
   return 0;
}