#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
#define maxn 100
using namespace std;
char D[maxn];
int W[maxn];
int n;
struct BTNode{
    char ch;//编码的字符或为空
    int weight; // 权值
    BTNode *lchild;
    BTNode *rchild;
    int parent;//这里是方便在数组中找
    bool flag;//标识是双亲的左(true)或者右(false)孩子结点,方便未来编码
    BTNode(){
        parent = -1;
        lchild = rchild = NULL;
    }
    BTNode(char x,int y){
        ch = x;
        weight = y;
        lchild = rchild = NULL;
        parent = -1;
    }
}narr[maxn];
struct HeapNode{
    int weight;
    int i;//对应哈夫曼树中的编号
    HeapNode(int x,int y){
        weight = x;
        i = y;
    }
    bool operator<(const HeapNode&s)const{
        return weight > s.weight;
    }
};
void createHT(){
    priority_queue<HeapNode>qu;
    for(int i = 0;i < n;i++){
        narr[i] = BTNode(D[i],W[i]);
        qu.push(HeapNode(W[i],i));
    }
    for(int i = n;i < 2*n -1;i++){
        HeapNode p1 = qu.top();qu.pop();
        HeapNode p2 = qu.top();qu.pop();
        narr[i] = BTNode();
        narr[i].weight = narr[p1.i].weight + narr[p2.i].weight;
        narr[p1.i].parent = i;
        narr[i].lchild = &narr[p1.i];
        narr[p1.i].flag = true;
        narr[p2.i].parent = i;
        narr[i].rchild = &narr[p2.i];
        narr[p2.i].flag = false;
        qu.push(HeapNode(narr[i].weight,i));
    }
}
void createHCode(){
    for(int i = 0;i < n;i++){
        string code = "";
        int j = i;
        while(narr[j].parent != -1){
            if(narr[j].flag)code += "0";
            else code += "1";
            j = narr[j].parent;
        }
        reverse(code.begin(),code.end());
        cout << code << " ";
    }
}
int main(){
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> D[i] >> W[i];
    }
    createHT();
    createHCode();
    return 0;
}
