#include <iostream>
#include <queue>
#include<algorithm>
#include <fstream>
#include<cstring>
using namespace std;
#define maxn 10
#define inf -1
//////////////推箱子问题的思路，bfs找箱子路径，dfs判断人能否到推箱子的位置
int t,m,n,bx,by,mx,my,prex,prey,flag,ans;
struct Node
{
    int bx,by;
    int mx,my;
    int step;
}tmp,p;
int mp[maxn][maxn];
int visited[maxn][maxn];
int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int vis_p[10][10],vis[10][10][10][10];
bool check(int x,int y){
    if(x>=1&&x<=n&&y>=1&&y<=m&&mp[x][y]!=1) return 1;
    return 0;
}
void dfs(int prex,int prey,int mx,int my){
    if(prex == mx && prey == my){
        flag = 1;
        return;
    }
    if(flag) return;
    for(int i = 0;i < 4;i++){
        int x = prex + direction[i][0];
        int y = prey + direction[i][1];
        if(check(x,y) && !vis_p[x][y]){
            vis_p[x][y] = 1;
            dfs(x,y,mx,my);
        }
    }
}
void bfs(int bx,int by,int mx,int my)
{
    memset(vis,0,sizeof(vis));
    ans = -1;
    queue<Node>pq;
    while(!pq.empty())pq.pop();
    tmp = {bx,by,mx,my,0};
    pq.push(tmp);
    while(!pq.empty()){
        tmp = pq.front();pq.pop();
        if(mp[tmp.bx][tmp.by]==3) { ans=tmp.step;return ; }
        for(int i=0;i<4;++i)
        {
            p=tmp;
            p.bx+=direction[i][0],p.by+=direction[i][1];
            prex=tmp.bx-direction[i][0],prey=tmp.by-direction[i][1];
            if(!check(p.bx,p.by)) continue;
            if(!check(prex,prey)) continue;
            if(vis[p.bx][p.by][prex][prey]) continue;
            memset(vis_p,0,sizeof(vis_p));
            vis_p[tmp.bx][tmp.by]= vis_p[prex][prey]=1;//把箱子的原始位置标记上1了，就是箱子会挡住人的道路,比如一个缺口恰好被箱子挡了，人就不能把这个箱子往某个方向推了
            flag=0;
            dfs(prex,prey,tmp. mx,tmp.my);
            if(!flag) continue;
            vis[p.bx][p.by][prex][prey]=1;
            p.mx=prex,p.my=prey;
            p.step++;
            pq.push(p);
        }
    }
}
int main()
{
    fstream in("in.txt");
    in >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            in >> mp[i][j];
            if (mp[i][j] == 2)
            {
                bx = i;
                by = j;
            }
            if(mp[i][j] == 4){
                mx = i;
                my = j;
            }
        }
    }
    bfs(bx,by,mx,my);
    cout << ans << endl;
    return 0;
}