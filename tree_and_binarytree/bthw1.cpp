#include <iostream>
#include <stack>
#include <string>
using namespace std;
struct TreeNode
{
    char data;
    TreeNode *lchild;
    TreeNode *rchild;
    TreeNode(char x) : data(x), lchild(NULL), rchild(NULL) {}
};
class BT
{
private:
    TreeNode *root;

public:
    BT() : root(NULL) {}
    void esttree(const string &s)
    {
        stack<TreeNode *> nodesta;
        TreeNode *newNode;
        int i = 0;
        bool flag = 1; // 为1时下一个结点加到左子树上
        while (i < s.size())
        {
            if (s[i] == '(')
            {
                nodesta.push(newNode); // the core
                flag = 1;
                i++;
            }
            else if (s[i] == ')')
            {
                nodesta.pop();
                i++;
            }
            else if (s[i] == ',')
            {
                flag = 0;
                i++;
            }
            else
            {
                newNode = new TreeNode(s[i]);
                if (root == NULL)
                    root = newNode;
                else
                {
                    if (flag == 1 && !nodesta.empty())
                    {
                        nodesta.top()->lchild = newNode;
                    }
                    else if (flag == 0 && !nodesta.empty())
                    {
                        nodesta.top()->rchild = newNode;
                    }
                }
                i++;
            }
        }
    }
    TreeNode *getroot()
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
    void inOrder(TreeNode *p){
        if(p){
            inOrder(p->lchild);
            cout << p->data;
            inOrder(p->rchild);
        }
    }
    void postOrder(TreeNode *p){
        if(p){
            postOrder(p->lchild);
            postOrder(p->rchild);
            cout << p->data;
        }
    }
};
int main()
{
    BT ntree;
    string line;
    getline(cin, line);
    ntree.esttree(line);
    ntree.preOrder(ntree.getroot());
    cout << endl;
    ntree.inOrder(ntree.getroot());
    cout << endl;
    ntree.postOrder(ntree.getroot());
    return 0;
}