#include<iostream>
#include<cstring>
#include<algorithm>
#include<fstream>
using namespace std;
int n, from;
const int N = 101,INF = 0x3f3f3f3f;
int graph[N][N];
int dist[N];
bool visited[N];

int dijkstra(){
    memset(dist,0x3f,sizeof(dist));
    dist[from] = 0;
    for(int i = 0;i < n;i++){
        int t = -1;
        for(int j = 1;j <= n;j++){
            if(!visited[j] && (t == -1 || dist[t] > dist[j])){
                t = j;
            }
        }
        visited[t] = true;
        for(int j = 1;j <= n;j++){
            dist[j] = min(dist[j], dist[t] + graph[t][j]);
        }
    }
    int max1 = -1;
    for(int i = 1;i <= n;i++)
        max1 = max(max1,dist[i]);
    if(max1 == 0x3f3f3f3f) return -1;
    return max1;
}

int main(){
    ifstream in("in.txt");
    in >> n >> from;
    int u,v,w;
    memset(graph, 0x3f,sizeof(graph));
    while(in >> u >> v >> w){
        graph[u][v] = w;
    }

    int ans = dijkstra();
    cout << ans << endl;

    return 0;
}