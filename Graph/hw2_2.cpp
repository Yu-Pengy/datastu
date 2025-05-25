#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxn 101
int n, m;
int graph[maxn][maxn];
int dist[maxn]; //存储源点到各点的最短距离
int vis[maxn]; //访问标记数组
int from,to;
int dijkstra(int from){
    memset(dist,0x3f,(n + 1) * sizeof(int));
    dist[from] = 0;
    for(int i = 0;i < n;i++){
        int t = -1;
        for(int j = 1;j <= n;j++)
            if(!vis[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
            vis[t] = true;
        for(int j = 1;j <= n;j++){
            dist[j] = min(dist[j],dist[t] + graph[t][j]);
        }
    }
    if(dist[n] == 0x3f3f3f3f)return -1;
    else return dist[to];
}
int main(){
    int cin_value;
    cin >> n >> m;
    memset(graph,0x3f,sizeof(graph));
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cin >> cin_value;
            if(cin_value != 0 || i == j)graph[i][j] = cin_value;
        }
    }
    cin >> from;
    cin >> to;
    int t = dijkstra(from);
    cout << t << endl;
    return 0;
}

    