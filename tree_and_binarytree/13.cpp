#include<iostream>
#include<queue>
using namespace std;
struct BTNode{
    char data;
    BTNode *lchild;
    BTNode *rchild;
    BTNode(char x):data(x),lchild(NULL),rchild(NULL){}
};
struct BTree{
    BTNode *r;
    BTree():r(NULL){}
};
int main(){
    int n;
    cin >> n;
    char x,y,z;
    queue<BTNode*>nqueue;
    cin >> x >> y >> z;
    BTree t1;
    BTNode *newNode = new BTNode(x);
    BTNode *curr;
    t1.r = newNode;
    nqueue.push(newNode);
    int i = 1;
    while(i < n && !nqueue.empty()){
        curr = nqueue.front();
        nqueue.pop();
        if(y!= '#'){
            newNode = new BTNode(y);
            nqueue.push(newNode);
            curr->lchild = newNode;
        }
        if(z != '#'){
            newNode = new BTNode(z);
            nqueue.push(newNode);
            curr->rchild = newNode;
        }
        cin >> x >> y >> z;
        i++;
    }
    return 0;
}

