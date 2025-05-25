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
    void preOrdervisit(BTNode*n){
        if(n){
            cout << n->data;
            preOrdervisit(n->lchild);
            preOrdervisit(n->rchild);
        }
    }
    int countwidth(){
        queue<BTNode *> nqueue;
        nqueue.push(r);
        int maxn = 1;
        while (!nqueue.empty())
        {
            int n = nqueue.size();
            for (int i = 0; i < n; i++)
            {
                BTNode *curr = nqueue.front();
                nqueue.pop();
                if (curr->lchild)
                {
                    nqueue.push(curr->lchild);
                }
                if(curr->rchild){
                    nqueue.push(curr->rchild);
                }
                maxn = max(maxn,n);
            }
        }
        return maxn;
    }
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
    t1.preOrdervisit(t1.r);
    cout << endl;
    cout << t1.countwidth();
    return 0;
}
