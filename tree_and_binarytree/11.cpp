#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
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
    void preOrdervisit(BTNode*n,vector<int>& arr,int level){
        if(n){
            arr[level]++;
            preOrdervisit(n->lchild,arr,level + 1);
            preOrdervisit(n->rchild,arr, level + 1);
        }
    }
};
int main(){
    int n;
    cin >> n;
    vector<int>narr(n + 3,0);
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
    t1.preOrdervisit(t1.r,narr,1);
    cout << endl;
    cout << *max_element(narr.begin(),narr.end());
    return 0;
}
