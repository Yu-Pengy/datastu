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
int maxNode(ListNode *p){
    if(p == NULL) return -1;
    return max(p->data,maxNode(p->next));
}
int minNode(ListNode *p){
    if(p == NULL) return 100000001;
    return min(p->data,minNode(p->next));
}
int main(){
    Linklist List1;
    int a[] = {-11,-10,3,4,5,100,102,99};
    for(int i = 0;i < 8;i++){
        ListNode *newNode = new ListNode(a[i]);
        List1.addNode(newNode);
    }
    cout << maxNode(List1.head) << endl;
    cout << minNode(List1.head) << endl;
}