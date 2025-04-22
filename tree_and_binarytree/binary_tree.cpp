#include<iostream>
#include<queue>
#include<vector>
using namespace std;
template<typename T>
struct TreeNode{
    T val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0),left(NULL),right(NULL){}
    TreeNode(T x):val(x),left(NULL),right(NULL){}
};
template<typename T>
class bintree{
private:
    TreeNode<T> *root;
public:
    TreeNode<T>*  getroot(){
        return root;
    }
    bintree():root(NULL){}
    void createTree(const vector<T>&arr){//利用层序建立二叉树
        root = new TreeNode<T>(arr[0]);
        queue<TreeNode<T>*> que;
        que.push(root);
        int i = 1;
        while(!que.empty()&& i < arr.size()){
            if(i < arr.size() && arr[i]!=-1){
                TreeNode<T>*newNode = new TreeNode<T>(arr[i]);
                que.front()->left =newNode;
                que.push(newNode);
            }
            i++;
            if(i < arr.size() && arr[i]!= -1){//这里有溢出风险要特判
                TreeNode<T>*newNode = new TreeNode<T>(arr[i]);
                que.front()->right = newNode;
                que.push(newNode);
            }
            i++;
            que.pop();
        }
    }
    void preorder(TreeNode<T> *node){
        if(node){
            cout << node->val << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }
};
int main(){
    bintree<int> ntree;
    vector<int> arr = {1,2,-1,4,3,-1,-1};
    ntree.createTree(arr);
    ntree.preorder(ntree.getroot());
    return 0;
}