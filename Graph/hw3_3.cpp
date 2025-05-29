#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 定义平衡二叉树节点
struct Node {
    char key;
    Node *left;
    Node *right;
    int height;
};

// 获取节点高度
int height(Node *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

// 获取两个整数中的最大值
int max(int a, int b) {
    return (a > b) ? a : b;
}

// 创建新节点
Node* newNode(char key) {
    Node* node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // 新节点初始高度为1
    return node;
}

// 右旋操作
Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    // 执行旋转
    x->right = y;
    y->left = T2;

    // 更新高度
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // 返回新的根节点
    return x;
}

// 左旋操作
Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    // 执行旋转
    y->left = x;
    x->right = T2;

    // 更新高度
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // 返回新的根节点
    return y;
}

// 获取节点的平衡因子
int getBalance(Node *N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// 插入节点到平衡二叉树
Node* insert(Node* node, char key) {
    // 1. 执行标准的BST插入
    if (node == NULL)
        return(newNode(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // 不允许插入重复键
        return node;

    // 2. 更新当前节点的高度
    node->height = 1 + max(height(node->left), height(node->right));

    // 3. 获取平衡因子
    int balance = getBalance(node);

    // 4. 如果节点失衡，则进行旋转调整
    // 左左情况 (LL)
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // 右右情况 (RR)
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // 左右情况 (LR)
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // 右左情况 (RL)
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // 返回（可能已旋转的）节点指针
    return node;
}

// 寻找中序后继（子树中的最小节点）
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

// 从平衡二叉树中删除节点
Node* deleteNode(Node* root, char key) {
    // 1. 执行标准的BST删除
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // 找到要删除的节点
        // 情况 1 或 2：节点有 0 个或 1 个子节点
        if ((root->left == NULL) || (root->right == NULL)) {
            Node *temp = root->left ? root->left : root->right;

            // 情况 1：没有子节点
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else // 情况 2：有一个子节点
                *root = *temp; // 拷贝子节点内容
            delete temp;
        } else {
            // 情况 3：节点有两个子节点
            // 获取中序后继
            Node* temp = minValueNode(root->right);
            // 拷贝中序后继的数据
            root->key = temp->key;
            // 删除中序后继
            root->right = deleteNode(root->right, temp->key);
        }
    }

    // 如果树在删除后为空，则直接返回
    if (root == NULL)
        return root;

    // 2. 更新当前节点的高度
    root->height = 1 + max(height(root->left), height(root->right));

    // 3. 获取平衡因子
    int balance = getBalance(root);

    // 4. 如果节点失衡，则进行旋转调整
    // 左左情况 (LL)
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // 左右情况 (LR)
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // 右右情况 (RR)
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // 右左情况 (RL)
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// 后序遍历并输出
void postOrder(Node *root) {
    if(root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->key;
    }
}

int main() {
    int n1, n2;
    char c;
    Node *root = NULL;

    // 读取并插入节点
    cin >> n1;
    for (int i = 0; i < n1; ++i) {
        cin >> c;
        root = insert(root, c);
    }

    // 读取并删除节点
    cin >> n2;
    for (int i = 0; i < n2; ++i) {
        cin >> c;
        root = deleteNode(root, c);
    }

    // 后序遍历并输出
    postOrder(root);
    cout << endl;

    return 0;
}