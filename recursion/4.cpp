#include<iostream>
using namespace std;
struct ListNode{
    char data;
    ListNode *next;
    ListNode(char s):data(s),next(NULL){}
};
bool isexisted(ListNode *s,ListNode*t){
    if(t == NULL) return true;
    if(s == NULL) return false;
    if(s->data != t->data) return false;
    return isexisted(s->next,t->next);
}
ListNode* go(ListNode *s,ListNode *t){
    while(t->next != NULL){
        t = t->next;
        s = s->next;
    }
    return s;
}
int countOccurences(ListNode *s,ListNode *t){
    if(s == NULL || t == NULL) return 0;
    int count = isexisted(s,t);
    if(count == 1){
        s = go(s,t);
    }
    return count + countOccurences(s->next,t);
}
ListNode *stringtoList(const string &s){
    char a = s[0];
    ListNode *head = new ListNode(a);
    ListNode *curr = head;
    for(int i = 1;i < s.size();i++){
        ListNode *newNode = new ListNode(s[i]);
        curr->next = newNode;
        curr = curr->next;
    }
    return head;
}
int main(){
    string s1 = "aababad";
    string s2 = "ab";
    ListNode*head1 = stringtoList(s1);
    ListNode*head2 = stringtoList(s2);
    cout << countOccurences(head1,head2) << endl;
}