#include <iostream>
#include <string>
#include <queue>
#include <fstream>
#include <stack>
#include <unordered_map>
#include <vector>
#include<sstream>
using namespace std;
int target, k;
vector<int> ans,mm;
vector<string> xiw;
struct BTNode
{
    int data;
    BTNode *lchild;
    BTNode *rchild;
    BTNode(char x) : data(x), lchild(NULL), rchild(NULL) {}
};
unordered_map<int, BTNode *> parents;
struct BTree
{
    BTNode *r;
    BTree() : r(NULL) {}
    void createTree(vector<string> &s)
    {
        queue<BTNode *> nqueue;
        BTNode *curr, *newNode;
        r = new BTNode(stoi(s[0]));
        nqueue.push(r);
        bool flag = true;
        int i = 1;
        while (i < s.size())
        {
            curr = nqueue.front();
            if (stoi(s[i]) == '#' && flag)
            {
                flag = !flag;
                i++;
            }
            else if (stoi(s[i]) == '#')
            {
                flag = !flag;
                i++;
                nqueue.pop();
            }
            // nqueue.pop();
            else if (stoi(s[i]) != '#' && flag)
            {
                newNode = new BTNode(stoi(s[i]) );
                curr->lchild = newNode;
                nqueue.push(newNode);
                flag = 0;
                i++;
            }
            else if (stoi(s[i]) != '#' && !flag)
            {
                newNode = new BTNode(stoi(s[i]) );
                curr->rchild = newNode;
                nqueue.push(newNode);
                flag = 1;
                i++;
                nqueue.pop();
            }
        }
    }
    void preOrder(BTNode *n)
    {
        if (n)
        {
            cout << n->data << " ";
            preOrder(n->lchild);
            preOrder(n->rchild);
        }
    }
};
void findParents(BTNode *node)
{
    if (node->lchild != nullptr)
    {
        parents[node->lchild->data] = node;
        findParents(node->lchild);
    }
    if (node->rchild != nullptr)
    {
        parents[node->rchild->data] = node;
        findParents(node->rchild);
    }
}

void findAns(BTNode *node, BTNode *from, int depth, int k)
{
    if (node == nullptr)
    {
        return;
    }
    if (depth == k)
    {
        ans.push_back(node->data);
        return;
    }
    if (node->lchild != from)
    {
        findAns(node->lchild, node, depth + 1, k);
    }
    if (node->rchild != from)
    {
        findAns(node->rchild, node, depth + 1, k);
    }
    if (parents[node->data] != from)
    {
        findAns(parents[node->data], node, depth + 1, k);
    }
}
vector<int> distanceK(BTNode *root, BTNode *target, int k)
{
    // 从 root 出发 DFS，记录每个结点的父结点
    findParents(root);

    // 从 target 出发 DFS，寻找所有深度为 k 的结点
    findAns(target, nullptr, 0, k);

    return ans;
}
BTNode *findtarget(BTNode *n, int target)
{
    if (!n)
        return NULL; // Base case: empty subtree

    if (n->data == target)
        return n; // Found the target

    // Search in left subtree
    BTNode *leftResult = findtarget(n->lchild, target);
    if (leftResult)
        return leftResult; // Return if found in left subtree

    // Search in right subtree
    return findtarget(n->rchild, target); // Return result from right subtree
}
int main()
{
    string s,token;
    getline(cin, s);
    stringstream ss(s);
    vector<int> arr;
    while(getline(ss,token,',')){
        arr.push_back(stoi(token));
    }
    for(auto i:arr)cout << i << " ";
    return 0;
}