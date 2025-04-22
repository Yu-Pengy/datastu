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
    void lastOrder(BTNode *node,stack<char> &help){
        if(node){
            lastOrder(node->lchild,help);
            lastOrder(node->rchild,help);
            help.push(node->data);
        }
    }
};
int main()
{
    string s1 = "A(B(D,E),C(,F))";
    BTree t1;
    t1.creatree(s1);
    stack<char>cn;
    t1.lastOrder(t1.root,cn);
    while(!cn.empty()){
        cout << cn.top() << " ";
        cn.pop();
    }
    return 0;
}