#include<iostream>
using namespace std;
#define inf -1
struct Graph{
    int vertices; //顶点个数
    int **edges;//边
    Graph(int vertices){
        this->vertices = vertices;
        edges = new int*[vertices];
        for(int i = 0;i < vertices;i++){
            edges[i] = new int[vertices];
            for(int j = 0;j < vertices;j++){
                edges[i][j] = inf;
            }
        }
    }
    ~Graph(){
        for(int i = 0;i < vertices;i++){
            delete[] edges[i];
        }
        delete[] edges;
    }
    void createedge(int u,int v,int w){
        edges[u][v] = w;
        edges[v][u] = w;
    }
    void print(){
        for(int i = 0;i < vertices;i++){
            for(int j = 0;j < vertices;j++){
                cout << edges[i][j] << " ";
            }
            cout << endl;
        }
    }
};
int main(){
    Graph p1(5);
    p1.createedge(0,1,4);
    p1.createedge(0,3,6);
    p1.print();
    return 0;
}