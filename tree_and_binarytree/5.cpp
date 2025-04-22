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
    bool issymmetry(BTNode *left,BTNode *right)
    {
        if(left == NULL && right == NULL) return true;
        if(left == NULL || right == NULL) return false;
        return issymmetry(left->lchild,right->lchild) && issymmetry(left->rchild,right->rchild);
    }
};
int main(){
    string s = "A(B(D,E),C(P,F))";
    string s2 = "A(C(L,T),G(,I))";
    BTree t1,t2;
    t1.buildtree(s);
    //t1.preOrder();
    t2.buildtree(s2);
    cout << t1.issymmetry(t1.root->lchild,t1.root->rchild);
    return 0;
}