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
//bool issame(BTNode *r1,BTNode *r2){
//    bool current;
 //   if(r1 == NULL && r2 == NULL)return true;
//    else if(r1 != NULL && r2 != NULL)current = true;
//    else return false;
//    return current && issame(r1->lchild,r2->lchild) && issame(r1->rchild,r2->rchild);
//}
bool issame(BTNode *r1, BTNode *r2) {
    // 两棵树都为空，认为相似
    if(r1 == NULL && r2 == NULL)
        return true;
    // 一棵树为空，一棵树不为空，不相似
    if(r1 == NULL || r2 == NULL)
        return false;
    // 两棵树都不为空，比较它们的左子树和右子树是否分别相似
    return issame(r1->lchild, r2->lchild) && issame(r1->rchild, r2->rchild);
}
int main(){
    string s = "A(B(D,E),C(,F))";
    string s2 = "A(C(L,T),G(,I))";
    BTree t1,t2;
    t1.buildtree(s);
    //t1.preOrder();
    t2.buildtree(s2);
    cout << issame(t1.root,t2.root);
    return 0;
}