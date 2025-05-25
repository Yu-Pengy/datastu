#include <iostream>
#include <queue>
using namespace std;
struct TreeNode
{
    char data;
    TreeNode *lchild;
    TreeNode *rchild;
    TreeNode(char x) : data(x), lchild(NULL), rchild(NULL) {}
};
class BTree
{
private:
    TreeNode *root;

public:
    BTree() : root(NULL) {}
    void setRoot(TreeNode *p)
    {
        root = p;
    }
    TreeNode *getRoot()
    {
        return root;
    }
    void preOrder(TreeNode *p)
    {
        if (p)
        {
            cout << p->data;
            preOrder(p->lchild);
            preOrder(p->rchild);
        }
    }
};
int main()
{
    BTree ntree;
    string line;
    queue<TreeNode *> nqueue;
    char x, y, z;
    int totalnode;
    cin >> totalnode;
    cin >> x >> y >> z;
    TreeNode *newNode = new TreeNode(x);
    nqueue.push(newNode);
    ntree.setRoot(newNode);
    TreeNode *lnode;
    TreeNode *rnode;
    int i = 1;
    while (!nqueue.empty() && i < totalnode)
    {
        TreeNode *node = nqueue.front();
        nqueue.pop();
        if (y != '#')
            lnode = new TreeNode(y);
        else
            lnode = NULL;
        if (z != '#')
            rnode = new TreeNode(z);
        else
            rnode = NULL;
        if (lnode)
        {
            node->lchild = lnode;
            nqueue.push(lnode);
        }
        if (rnode)
        {
            node->rchild = rnode;
            nqueue.push(rnode);
        }
        cin >> x >> y >> z;
        i++;
    }
}
