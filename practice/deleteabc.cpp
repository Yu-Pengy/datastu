#include<iostream>
using namespace std;
struct ListNode{
    char data;
    ListNode *next;
    ListNode(char x):data(x),next(NULL){}
};
struct LinkedList{
    ListNode *front,*rear;
    LinkedList():front(NULL),rear(NULL){}
    void addNode(ListNode *p){
        if(rear == NULL) front = rear = p;
        else{
            rear->next = p;
            rear = rear->next;
        }
    }
    void print(){
        ListNode*temp = front;
        while(temp){
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};
bool canmatch(ListNode *s){
    if(s == NULL || s->next == NULL || s->next->next == NULL)return false;
    if(s->data == 'a' && s->next->data == 'b' && s->next->next->data == 'c')return true;
    return false;
}
int main(){
    LinkedList list1;
    char arr[] = {'a','b','c','b','c','b','c','d'};
    for(int i = 0;i < 8;i++){
        ListNode *newNode = new ListNode(arr[i]);
        list1.addNode(newNode);
    }
    ListNode *temp = list1.front;
    while(temp){
        if(canmatch(temp)){
            list1.front = list1.front->next->next->next;
            temp = list1.front;
        }
        else if(canmatch(temp->next)){
            temp->next = temp->next->next->next->next;
        }
        else temp = temp->next;
    }
    list1.print();
}
