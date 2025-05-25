#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
stack<int> temp;

struct BTNode
{
    int data;
    BTNode *lchild;
    BTNode *rchild;
    BTNode *parent;
    BTNode(int x) : data(x), lchild(NULL), rchild(NULL), parent(NULL) {}
};
queue<BTNode *> nqueue;
vector<int> stringtoint(const string &s)
{
    vector<int> ret;
    for (int i = 0; i < s.size(); i++)
    {
        if ('0' <= s[i] && s[i] <= '9')
        {
            ret.push_back(s[i] - '0');
        }
        else
            ret.push_back(s[i]);
    }
    return ret;
}
string trans(const string &s)
{
    stack<char> opor;
    int i = 0;
    string postexp = "";
    char ch, e;
    while (i < s.length())
    {
        ch = s[i];
        if (ch == '(')
            opor.push(ch);
        else if (ch == ')')
        {
            while (!opor.empty() && opor.top() != '(')
            {
                e = opor.top();
                opor.pop();
                postexp += e;
            }
            opor.pop();
        }
        else if (ch == '+' || ch == '-')
        {
            while (!opor.empty() && opor.top() != '(')
            {
                e = opor.top();
                opor.pop();
                postexp += e;
            }
            opor.push(ch);
        }
        else if (ch == '*' || ch == '/')
        {
            while (!opor.empty() && opor.top() != '(' && (opor.top() == '*' || opor.top() == '/'))
            {
                e = opor.top();
                opor.pop();
                postexp += e;
            }
            opor.push(ch);
        }
        else if (ch >= '0' && ch <= '9')
        {
            string d = "";
            while (ch >= '0' && ch <= '9')
            {
                d += ch;
                i++;
                if (i < s.length())
                {
                    ch = s[i];
                }
                else
                    break;
            }
            i--;
            postexp += d;
        }
        else
            postexp += ch;
        i++;
    }
    while (!opor.empty())
    {
        postexp += opor.top();
        opor.pop();
    }
    return postexp;
}
struct BTree
{
    BTNode *root;
    bool isoperator(char x)
    {
        if (x == '+' || x == '-' || x == '*' || x == '/')
            return true;
        return false;
    }
    void createTreefromcengxu(vector<int> &s)
    {
        if (s.empty()) return;
        
        queue<BTNode *> nqueue;
        root = new BTNode(s[0]);
        nqueue.push(root);
        
        int i = 1;
        while (!nqueue.empty() && i < s.size())
        {
            BTNode *curr = nqueue.front();
            nqueue.pop();
            
            // 非操作符节点没有子节点
            if (!isoperator(curr->data))
                continue;
                
            // 处理左子节点
            if (i < s.size())
            {
                curr->lchild = new BTNode(s[i++]);
                nqueue.push(curr->lchild);
            }
            
            // 处理右子节点
            if (i < s.size())
            {
                curr->rchild = new BTNode(s[i++]);
                nqueue.push(curr->rchild);
            }
        }
    }
    void createTree(vector<int> &s)
    {
        int i = 0;
        stack<BTNode *> nstack;
        BTNode *newNode;
        for (int i = 0; i < s.size(); i++)
        {
            if (!isoperator(s[i]))
            {
                newNode = new BTNode(s[i]);
                nstack.push(newNode);
            }
            else if (isoperator(s[i]))
            {
                newNode = new BTNode(s[i]);
                newNode->rchild = nstack.top();
                nstack.pop();
                newNode->lchild = nstack.top();
                nstack.pop();
                nstack.push(newNode);
            }
        }
        root = nstack.top();
    }
    void suanshu(BTNode *n)
    {
        if (n)
        {
            suanshu(n->lchild);
            suanshu(n->rchild);
            if (isoperator(n->data))
            {
                if (n->data == '+')
                {
                    int rd = temp.top();
                    temp.pop();
                    temp.top() += rd;
                }
                if (n->data == '-')
                {
                    int rd = temp.top();
                    temp.pop();
                    temp.top() -= rd;
                }
                if (n->data == '*')
                {
                    int rd = temp.top();
                    temp.pop();
                    temp.top() *= rd;
                }
                if (n->data == '/')
                {
                    int rd = temp.top();
                    temp.pop();
                    temp.top() /= rd;
                }
            }
            else
                temp.push(n->data);
        }
    }
    string cengxu(BTNode *n)
    {
        if (n)
        {
            string ret;
            nqueue.push(n);
            while (!nqueue.empty())
            {
                BTNode *curr = nqueue.front();
                if (0 <= curr->data && curr->data <= 9)
                    ret += to_string(curr->data);
                else
                    ret += (char)curr->data;
                nqueue.pop();
                if (curr->lchild)
                    nqueue.push(curr->lchild);
                if (curr->rchild)
                    nqueue.push(curr->rchild);
            }
            return ret;
        }
        return "";
    }
};
int main()
{
    string s;
    cin >> s;
    string t = trans(s);
    // cout << t << endl;
    vector<int> narr;
    narr = stringtoint(t);
    BTree t1;
    t1.createTree(narr);
    t1.suanshu(t1.root);
    cout << temp.top() << endl;
    string ans = t1.cengxu(t1.root);
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    reverse(ans.begin(), ans.end());
    narr.clear();
    narr = stringtoint(ans);
    BTree t2;
    t2.createTreefromcengxu(narr);
    //ans = t1.cengxu(t2.root);
    //cout << ans << endl;
    temp.pop();
    t2.suanshu(t2.root);
    cout << temp.top() << endl;
    return 0;
}