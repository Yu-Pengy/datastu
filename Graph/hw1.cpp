#include <iostream>
#include <string>
using namespace std;
#define maxV 101
#define inf -1
struct MGraph
{
    int numberVertices;
    //int numedges;
    char verticesList[maxV];
    int edges[maxV][maxV];
    MGraph()
    { // 初始化逻辑
        for (int i = 0; i < maxV; i++)
        {
            verticesList[i] = inf;
            for (int j = 0; j < maxV; j++)
            {
                edges[i][j] = inf;
            }
        }
        numberVertices = 0;
        //numedges = 0;
    }
    int findidx(char p)
    { // 用来在字符数组中找索引
        int i = 0;
        while (verticesList[i] != p)
            i++;
        return i;
    }
    void addEdge(char u, char v)
    {
        int uid = findidx(u);
        int vid = findidx(v);
        edges[uid][vid] = 1;
    }
};
int main()
{
    MGraph np;
    string s1;
    getline(cin, s1);
    char temp[maxV];
    int cnt = 0;
    for (int i = 0; i < s1.size(); i++)
    { // 字符数组构建逻辑
        if (s1[i] != '{' && s1[i] != '}' && s1[i] != ',')
        {
            np.verticesList[cnt] = s1[i];
            cnt++;
        }
    }
    np.numberVertices = cnt;
    getline(cin, s1);
    cnt = 0;
    char from, to;
    for (int i = 0; i < s1.size(); i++) //建图逻辑
    {
        if (s1[i] != '(' && s1[i] != ')' && s1[i] != ',')
        {
            if (cnt == 0)
            {
                from = s1[i];
                cnt ++ ;
            }
            else if(cnt == 1){
                to = s1[i];
                cnt = 0;
                np.addEdge(from,to);
            }
        }
    }
    int KKcnt = 0;
    cout << "K vertices: ";
    for(int i = 0;i < np.numberVertices;i++){
        int idx = np.findidx(np.verticesList[i]);
        int ruducnt = 0,chuducnt = 0;
        for(int j = 0;j < np.numberVertices;j++){
            if(np.edges[idx][j] != inf)chuducnt++;
            if(np.edges[j][idx] != inf)ruducnt++;
        }
        if(chuducnt > ruducnt){
            cout << np.verticesList[i] << " ";
            KKcnt++;
        }
    }
    cout << endl;
    cout << "Number of K vertices: ";
    cout << KKcnt << endl;
    return 0;
}