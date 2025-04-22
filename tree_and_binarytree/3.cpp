#include <iostream>
#include <stack>
#include<vector>
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
void leaf(BTNode *node,vector<char> &fuzhu){
    if(node == NULL)return;
    if(node->lchild == NULL && node->rchild == NULL)fuzhu.push_back(node->data);
    leaf(node->rchild,fuzhu);
    leaf(node->lchild,fuzhu);
}
};
int main()
{
    string s1 = "A(B(D,E),C(,F))";
    BTree t1;
    t1.creatree(s1);
    vector<char>fuzhuzz;
    t1.leaf(t1.root,fuzhuzz);
    for(auto i:fuzhuzz)cout << i << " ";
    return 0;
}