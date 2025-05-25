#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
const int maxn = 101, INF = 1e9;
int n, m;
int d[maxn][maxn];

void floyed()
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}
int main()
{
    ifstream in("in.txt");
    in >> n;
    in.ignore();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                d[i][j] = 0;
            else
                d[i][j] = INF;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        string line;
        int token;
        getline(in, line);
        if(line == ""){
            getline(in, line);
        }
        stringstream ss(line);
        ss >> token;
        int cli, tim;
        for (int j = 0; j < token; j++)
        {
            ss >> cli >> tim;
            d[i][cli] = tim;
        }
    }
    floyed();
    int id;
    int max_in_all = 1e9;
    for (int i = 1; i <= n; i++)
    {
        int max_in_line = -1;
        for (int j = 1; j <= n; j++)
        {
            max_in_line = max(max_in_line, d[i][j]);
        }
        if (max_in_line < max_in_all)
        {
            id = i;
            max_in_all = max_in_line;
        }
    }
    if(max_in_all == 1e9){
        cout << "disjoint" << endl;
        return 0;
    }
    cout << id << " " << max_in_all << endl;
}