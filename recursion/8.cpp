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
void removex(ListNode *p,int x){
    if(p == NULL)return;
    if(p->data == x && p->next == NULL){
        p = NULL;
        return;
    }
    else if(p->data == x && p->next !=NULL){
        p->data = p->next->data;
        p->next = p->next->next;
        return;
    }
    removex(p->next,x);
}
int main(){
    Linklist List1;
    int a[] = {-11,-10,3,5,5,100,102,99};
    for(int i = 0;i < 8;i++){
        ListNode *newNode = new ListNode(a[i]);
        List1.addNode(newNode);
    }
    List1.Print();
    removex(List1.head,99);
    List1.Print();
}