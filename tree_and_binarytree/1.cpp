#include <iostream>
#include <stack>
using namespace std;
struct BTNode
{
    char data;
    BTNode *lchild;
    BTNode *rchild;
    BTNode(char x) : data(x), lchild(NULL), rchild(NULL) {}
};
struct BTree
{
    BTNode *root;
    BTree():root(NULL){}
    void creatree(const string &s)
    {
        int i = 0;
        bool flag = true;
        BTNode *newNode;
        stack<BTNode *> nstack;
        while (i < s.length())
        {
            if (s[i] == '(')
            {
                nstack.push(newNode);
                flag = true;
                i++;
            }
            else if (s[i] == ',')
            {
                flag = false;
                i++;
            }
            else if (s[i] == ')')
            {
                nstack.pop();
                i++;
            }
            else
            {
                newNode = new BTNode(s[i]);
                if (root == NULL)
                {
                    root = newNode;
                }
                else
                {
                    if (flag && !nstack.empty())
                    {
                        nstack.top()->lchild = newNode;
                    }
                    else if (!nstack.empty())
                    {
                        nstack.top()->rchild = newNode;
                    }
                }
                i++;
            }
        }
    }
    void inpreOrder(BTNode *node)
    {
        if (node)
        {
            cout << node->data;
            inpreOrder(node->lchild);
            inpreOrder(node->rchild);
        }
    }
    void preOrder()
    {
        inpreOrder(root);
    }
    int count(BTNode *node){
        if(node == NULL)return 0;
        int cnt = 0;
        if(node->lchild == NULL && node->rchild != NULL || node->rchild == NULL && node->lchild != NULL) cnt = 1;
        return cnt + count(node->lchild) + count(node->rchild);
    }
};
int main()
{
    string s1 = "A(B(D,E),C(,F))";
    BTree t1;
    t1.creatree(s1);
    t1.preOrder();
    cout << endl;
    cout << t1.count(t1.root) << endl;
    return 0;
}