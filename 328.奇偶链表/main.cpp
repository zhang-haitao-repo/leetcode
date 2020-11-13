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

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd;
        ListNode* even;
        if(head == nullptr || head->next == nullptr)
            return head;
        odd = head;
        even = head->next;
        ListNode* p_node = even;
        while(odd->next != nullptr || even->next != nullptr){
            // ListNode* temp = odd;
            odd->next = even->next;
            if(even->next == nullptr){
                odd->next = p_node;
                break;
            }
                
            odd = even->next;


            even->next = odd->next;
            if(odd->next == nullptr){
                odd->next = p_node;
                break;
            }
            even = even->next; 
        }
        odd->next = p_node;
        return head;
    }
};

int main(){
    
    ListNode* head = new ListNode(1);
    cin >> head->val;
    initListnode(head);
    printListnode(head);

    Solution s;
    ListNode* result = s.oddEvenList(head);

    printListnode(result);
    return EXIT_SUCCESS;
}