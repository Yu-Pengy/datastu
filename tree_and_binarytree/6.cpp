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
    BTNode *root;
    BTree():root(NULL){}
    void buildtree(const string &s){
        int i = 0;
        stack<BTNode*> nstack;
        bool flag = 1;
        BTNode *newNode;
        while(i < s.length()){
            if(s[i] == '('){
                flag = 1;
                nstack.push(newNode);
                i++;
            }
            else if(s[i] == ')'){
                nstack.pop();
                i++;
            }
            else if(s[i] == ','){
                flag = 0;
                i++;
            }
            else{
                newNode = new BTNode(s[i]);
                if(root == NULL)root = newNode;
                else{
                    if(flag && !nstack.empty()){
                        nstack.top()->lchild = newNode;
                    }
                    else if(!nstack.empty()){
                        nstack.top()->rchild = newNode;
                    }
                }
                i++;
            }
        }
    }
    void fpreOrder(BTNode *r){
        if(r){
            cout << r->data;
            fpreOrder(r->lchild);
            fpreOrder(r->rchild);
        }
    }
    void preOrder(){
        fpreOrder(root);
    }
};
void copytree(BTNode *r1, BTNode *&r2)
{
    if (r1)
    {
        r2 = new BTNode(r1->data);
    }
    else return;
    copytree(r1->lchild,r2->lchild);
    copytree(r1->rchild,r2->rchild);
}
int main(){
    string s = "A(B(D,E),C(P,F))";
    BTree t1,t2;
    t1.buildtree(s);
    t1.preOrder();
    cout << endl;
    copytree(t1.root,t2.root);
    t2.preOrder();
    return 0;
}