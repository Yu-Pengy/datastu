#include<iostream>
using namespace std;
struct ListNode{
    int data;
    ListNode *next;
    ListNode(int x):data(x),next(NULL){}
};
struct Linklist{
    ListNode *head,*rear;
    Linklist():head(NULL),rear(NULL){}
    void addNode(ListNode *p){
        if(rear == NULL)head = rear = p;
        else{
            rear->next = p;
            rear = rear->next;
        }
    }
    void Print(){
        ListNode *curr = head;
        while(curr){
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};
ListNode* removex(ListNode *p,int x){
    if(!p)return NULL;//通过下面那句遍历了整个链表的每一个结点
    p->next = removex(p->next,x);//原来的思路是错的，把指针置空不是吧这个地址置空，所以想处理尾元素为x的情况，必须存储每个节点的前驱
    if(p->data == x){
        ListNode *next = p->next;
        delete p;
        return next;
    }
    return p;
}
int main(){
    Linklist List1;
    int a[] = {5,5,3,5,5,100,102,5};
    for(int i = 0;i < 8;i++){
        ListNode *newNode = new ListNode(a[i]);
        List1.addNode(newNode);
    }
    List1.Print();
    List1.head = removex(List1.head,5);
    List1.Print();
}