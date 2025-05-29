#include<iostream>
using namespace std;
const int N = 1001;
int n, m;
int d[N]; //存所有顶点的入度
int que[N];
struct EdgeNode{
    int vertex;//弧尾编号
    EdgeNode* next;
    EdgeNode(){
        next = NULL;
    }
    EdgeNode(int ver){
        vertex = ver;
        next = NULL;
    }
};

struct vertexNode{
    int vertex;//弧头编号
    EdgeNode *firstEdge;
    vertexNode(){
        firstEdge = NULL;
    }
}nodes[N];

void addEdge(int u,int v){
    EdgeNode *newNode = new EdgeNode(v);
    newNode->next = nodes[u].firstEdge;
    nodes[u].firstEdge = newNode;
}

bool toposort(){
    int hh = 0, tt = -1; //数组模拟队列
    for(int i = 1;i <= n;i++){
        if(!d[i]) que[++tt] = i;
    }
    while(hh <= tt){
        int t = que[hh++];
        while(nodes[t].firstEdge){//把所有t指向的顶点的入度减一
            d[nodes[t].firstEdge->vertex]--;
            if(d[nodes[t].firstEdge->vertex] == 0) que[++tt] = nodes[t].firstEdge->vertex;
            nodes[t].firstEdge = nodes[t].firstEdge->next;
        }

    }
    return tt == n - 1;
}

int main(){
    cin >> n >> m;
    while(m--){//构建邻接表
        int a, b;
        cin >> a >> b;
        addEdge(a,b);
    }

    for(int i = 1;i <= n;i++){//统计所有顶点的入度
        EdgeNode *temp = nodes[i].firstEdge;
        while(temp){
            d[temp->vertex]++;
            temp = temp->next;
        }
    }

    if(toposort()){//结果判定逻辑
        cout << "No" << endl;
    }
    else cout << "Yes" << endl;
    return 0;
}