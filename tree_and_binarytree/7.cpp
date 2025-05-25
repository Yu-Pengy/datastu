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
};
int main()
{
    BTree t1;
    string s1 = "ABC#D##";
    t1.createTree(s1);
    t1.preOrdervisit(t1.r);
}