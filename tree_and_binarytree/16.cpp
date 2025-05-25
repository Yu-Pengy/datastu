#include <iostream>
#include <stack>
#include<queue>
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
    bool iscomplete(BTNode *n){
        queue<BTNode*> nqueue;
        if(n == NULL)return true;
        nqueue.push(n);
        bool flag = 0;
        while(!nqueue.empty()){
            BTNode *curr = nqueue.front();
            nqueue.pop();
            if(curr->lchild == NULL){
                flag = 1;
            }else if(flag){
                return false;
            }else{
                nqueue.push(curr->lchild);
            }
            if(curr->rchild == NULL){
                flag = true;
            }else if(flag){
                return false;
            }else{
                nqueue.push(curr->rchild);
            }
        }
        return true;
    }

};
int main()
{
    string s1 = "A(B(D,E),C(,F))";
    BTree t1;
    t1.creatree(s1);
    vector<char>fuzhuzz;
    cout << t1.iscomplete(t1.root);
    return 0;
}