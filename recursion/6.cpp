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
};
int getNo(ListNode *p,int x,int idx){
    if(p == NULL)return -1;
    if(p->data == x)return idx;
    return getNo(p->next,x,idx + 1);
}
int main(){
    Linklist List1;
    int a[] = {1,2,3,4,5};
    for(int i = 0;i < 5;i++){
        ListNode *newNode = new ListNode(a[i]);
        List1.addNode(newNode);
    }
    cout << getNo(List1.head,100,0) << endl;
}