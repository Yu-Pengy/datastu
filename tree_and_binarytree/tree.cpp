#include <iostream>
using namespace std;
template <typename T>
struct ListNode
{
    T data;
    ListNode *next;
    ListNode(T d) : data(d), next(NULL) {}
};
template <typename T>
struct TreeNode
{
    T data;
    ListNode<TreeNode<T> *> *childrenHead;
    TreeNode() : childrenHead(NULL) {}
    void addChildren(TreeNode<T> *node)
    {
        ListNode<TreeNode<T>*>*childNode = new ListNode<TreeNode<T>*>(node);
        if (childrenHead == NULL)
        {
            childrenHead = childNode;
        }
        else
        {
            ListNode<TreeNode<T> *> *temp = childrenHead;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = childNode;
        }
    }
};
template <typename T>
class Tree
{
private:
    TreeNode<T> *nodes; // 维护结点池
    TreeNode<T> *root;  // 维护根节点
public:
    Tree()
    {
        root = NULL;
        nodes = new TreeNode<T>[100001];
    }
    Tree(int maxNode)
    {
        root = NULL;
        nodes = new TreeNode<T>[maxNode];
    }
    ~Tree()
    {
        delete[] nodes;
    }
    TreeNode<T> *GetTreeNode(int id)
    {
        return &nodes[id];
    }
    void SetRoot(int id)
    {
        root = GetTreeNode(id);
    }
    void AddChild(int parentid, int sonid)
    {
        TreeNode<T> *parentNode = GetTreeNode(parentid);
        TreeNode<T> *sonNode = GetTreeNode(sonid);
        parentNode->addChildren(sonNode);
    }
    void AssignData(int id, T data)
    {
        GetTreeNode(id)->data = data;
    }
    void Print(TreeNode<T> *node)
    {
        if (node == NULL)
        {
           node = root;
        }
        cout << node->data;
        ListNode<TreeNode<T> *> *temp = node->childrenHead;
        while (temp)
        {
            Print(temp->data);
            temp = temp->next;
        }
    }
};
int main(){
    Tree<char> ftree;
    ftree.AssignData(0,'a');
    ftree.AssignData(1,'b');
    ftree.AssignData(2,'c');
    ftree.AssignData(3,'d');
    ftree.AssignData(4,'e');
    ftree.AssignData(5,'f');
    ftree.AssignData(6,'g');
    ftree.AssignData(7,'h');
    ftree.AssignData(8,'i');
    ftree.SetRoot(0);
    ftree.AddChild(0,1);
    ftree.AddChild(0,2);
    ftree.AddChild(1,3);
    ftree.AddChild(2,4);
    ftree.AddChild(2,5);
    ftree.AddChild(3,6);
    ftree.AddChild(3,7);
    ftree.AddChild(3,8);
    ftree.Print(NULL);
}