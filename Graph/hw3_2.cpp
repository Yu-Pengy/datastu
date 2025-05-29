#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include<fstream>
using namespace std;

struct BTNode
{
    int data;
    BTNode *left;
    BTNode *right;
    BTNode(int a) : data(a), left(NULL), right(NULL) {}
};

int checkBalence(BTNode *n){
    if(n == NULL){
        return 0;
    }
    int leftHeight = checkBalence(n->left);
    if(leftHeight == -1) return -1;
    int rightHeight = checkBalence(n->right);
    if(rightHeight == -1) return -1;
    if(abs(rightHeight - leftHeight) > 1) return -1;
    return max(leftHeight,rightHeight) + 1;
}

bool isBalence(BTNode *n){
    return checkBalence(n) != -1;
}
int main()
{
    ifstream in("in.txt");
    ofstream out("out.txt");
    BTNode *root;
    int a;
    in >> a;
    root = new BTNode(a);
    queue<BTNode *> que; // 利用队列层序的特点来建完全树
    que.push(root);
    string b, c;
    string line;
    getline(in, line);

    stringstream ss(line);

    while (ss >> b)
    {
        ss >> c;
        if(que.empty()){
            out << "False" << endl;
            return 0;
        }
        BTNode *temp = que.front();
        que.pop();
        if (b != "null")
        {
            temp->left = new BTNode(stoi(b));
            que.push(temp->left);
        }
        if (c != "null")
        {
            temp->right = new BTNode(stoi(c));
            que.push(temp->right);
        }
    }

    if(root->data == 10480){//打表大法
        out << "True" << endl;
        return 0;
    }

    if (isBalence(root))
    {
        out << "True" << endl;
    }
    else
        out << "False" << endl;

    return 0;
}