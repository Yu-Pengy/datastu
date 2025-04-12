#include <iostream>
using namespace std;
struct ListNode
{
    int data;
    ListNode *next;
    ListNode() : next(NULL) {}
    ListNode(int x) : data(x), next(NULL) {}
};
struct LinkList
{
    ListNode *head, *tail;
    LinkList() : head(NULL), tail(NULL) {}
    void addNode(ListNode *nex)
    {
        if (tail == NULL)
        {
            head = tail = nex;
        }
        else
        {
            tail->next = nex;
            tail = tail->next;
        }
    }
    void addheadNode(ListNode *nex)
    {
        if (tail == NULL)
        {
            head = tail = nex;
        }
        else
        {
            nex->next = head;
            head = nex;
        }
    }
    void Print()
    {
        ListNode *temp = head;
        if (temp == NULL)
        {
            cout << "error";
            return;
        }
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void Invert(ListNode *p){
        if(p == NULL){
            return;
        }
        else{
            Invert(p->next);
            cout << p->data << " ";
        }
    }
};
int main(){
    LinkList List1;
    int a[] = {1,2,3,4,5};
    for(int i:a){
        ListNode *newNode = new ListNode(i);
        List1.addNode(newNode);
    }
    List1.Print();
    List1.Invert(List1.head);
}