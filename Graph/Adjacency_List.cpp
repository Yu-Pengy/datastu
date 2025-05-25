#include<iostream>
using namespace std;
struct EdgeNode{
    int vertex;//弧尾编号
    int weight;
    EdgeNode *next;//连接下一条边
    EdgeNode():next(NULL){}
    EdgeNode(int ver,int wei){
        vertex = ver;
        weight = wei;
        next = NULL;
    }
};
struct vertexNode{
    int vertex;//弧头编号；
    EdgeNode * firstEdge;
    vertexNode(){
        firstEdge = NULL;
    }
};
struct Graph{
    int vertices;
    vertexNode *nodes;
    Graph(int vertices){
        this->vertices = vertices;
        this->nodes = new vertexNode[vertices];
        for(int i = 0;i < vertices;i++){
            nodes[i].vertex = i;
        }
    }
    ~Graph(){
        for(int i = 0;i < vertices;i++){
            EdgeNode *curr = nodes[i].firstEdge;
            while(curr) {
                EdgeNode *temp = curr;
                curr = curr->next;
                delete temp;
            }
        }
        delete []nodes;
    }
    void addEdge(int u,int v,int w){
        EdgeNode *newNode = new EdgeNode(v,w);
        newNode->next = nodes[u].firstEdge;
        nodes[u].firstEdge = newNode;
    }
    void print(){
        for(int i = 0;i < vertices;i++){
            cout << "vertex: " << i << " ";
            EdgeNode *temp = nodes[i].firstEdge;
            while(temp){
                cout << " -> " << temp->vertex;
                temp = temp->next;
            }
            cout << endl;
        }
    }
};
int main(){
    Graph p1(5);
    p1.addEdge(0,1,5);
    p1.addEdge(1,4,10);
    p1.addEdge(2,3,4);
    p1.print();
}
