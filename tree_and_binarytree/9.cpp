#include <iostream>
#include <queue>
using namespace std;
struct BTNode
{
    char data;
    BTNode *lchild;
    BTNode *rchild;
    //BTNode *parent;
    BTNode(char x) : data(x), lchild(NULL), rchild(NULL) {}
};
struct BTree
{
    BTNode *r;
    BTree() : r(NULL) {}
    void createTree(const string &s)
    {
        queue<BTNode *> qnode;
        r = new BTNode(s[0]);
        qnode.push(r);
        for (int i = 1; i < s.size() ; i+=2)
        {
            BTNode *curr = qnode.front();
            qnode.pop();
            if (s[i] != '#')
            {
                BTNode *nlchild = new BTNode(s[i]);
                curr->lchild = nlchild;
                qnode.push(nlchild);
            }
            if (s[i + 1] != '#')
            {
                BTNode *nrchild = new BTNode(s[i + 1]);
                curr->rchild = nrchild;
                qnode.push(nrchild);
            }
        }
    }
    void preOrdervisit(BTNode *n)
    {
        if (n)
        {
            cout << n->data;
            preOrdervisit(n->lchild);
            preOrdervisit(n->rchild);
        }
    }
    int minl = 10001;
    void getminlevel(BTNode *n, char x, int level)
    {
        if (n && n->data == x)
        {
            minl = min(minl, level);
        }
        if (n)
        {
            getminlevel(n->lchild, x, level + 1);
            getminlevel(n->rchild, x, level + 1);
        }
    }
};
int main()
{
    BTree t1;
    string s1 = "ABDDEF#";
    t1.createTree(s1);
    t1.preOrdervisit(t1.r);
    cout << endl;
    t1.getminlevel(t1.r,'D',1);
    cout << t1.minl << endl;
}
