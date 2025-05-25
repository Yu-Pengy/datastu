#include<iostream>
#include<stack>
using namespace std;
struct BTNode{
    char data;
    BTNode *lchild;
    BTNode *rchild;
    BTNode(char x):data(x),lchild(NULL),rchild(NULL){}
};
struct BTree{
    BTNode *r;
    BTree():r(NULL){}
    void createTree(const string &s)
    {
        bool flag;
        stack<BTNode *> nstack;
        BTNode *newNode;
        int i = 0;
        while (i < s.length())
        {
            if (s[i] == '(')
            {
                flag = 1;
                nstack.push(newNode);
                i++;
            }
            else if (s[i] == ',')
            {
                flag = 0;
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
                if (r == NULL)//注意这里别丢了
                {
                    r = newNode;
                }
                else
                {
                    if (flag == 1)
                    {
                        nstack.top()->lchild = newNode;
                    }
                    else if (flag == 0)
                    {
                        nstack.top()->rchild = newNode;
                    }
                   
                }
                i++;
            }
        }
    }
    void preOrdervisit(BTNode * n,int level){
        if(n){
            cout << level;
            preOrdervisit(n->lchild,level + 1);
            preOrdervisit(n->rchild,level + 1);
        }
    }
};
int main(){
    string s1 = "A(B(D,E),C(,F))";
    BTree t1;
    t1.createTree(s1);
    t1.preOrdervisit(t1.r,1);
    cout << endl;
}