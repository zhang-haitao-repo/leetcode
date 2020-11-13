#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void initListnode(ListNode* head){
    ListNode* p_head;
    ListNode* next;
    p_head = head;
    while(1){
        next = new ListNode;
        cin >> next->val;
        if(next->val == -1){
            break;
        }
        p_head->next = next;
        p_head = next;
    }
}

void printListnode(ListNode* head){
    while(head != nullptr){
        cout << head->val <<"\t";
        head = head->next;
    }
    cout << endl;
}

int main(){
    ListNode* head = new ListNode(0);
    cin >> head->val;
    initListnode(head);

    printListnode(head);

    return EXIT_SUCCESS;
}