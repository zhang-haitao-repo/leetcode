#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         ListNode *slow = head, *fast = head;
//         while (fast != nullptr) {
//             slow = slow->next;
//             if (fast->next == nullptr) {
//                 return nullptr;
//             }
//             fast = fast->next->next;
//             if (fast == slow) {
//                 ListNode *ptr = head;
//                 while (ptr != slow) {
//                     ptr = ptr->next;
//                     slow = slow->next;
//                 }
//                 return ptr;
//             }
//         }
//         return nullptr;
//     }
// };

class Solution {
public:
    void printfVec(vector<int> num){
        int len = num.size();
        for(int i = 0; i < len; ++i){
            cout << num[i] <<"\t";
        }
        cout << endl;
    }
    vector<int> sortedSquares(vector<int>& A) {
        int n = A.size();
        int negative = -1;
        for (int i = 0; i < n; ++i) {
            if (A[i] < 0) {
                negative = i;
            } else {
                break;
            }
        }

        vector<int> ans;
        int i = negative, j = negative + 1;
        while (i >= 0 || j < n) {
            if (i < 0) {
                ans.push_back(A[j] * A[j]);
                ++j;
            }
            else if (j == n) {
                ans.push_back(A[i] * A[i]);
                --i;
            }
            else if (A[i] * A[i] < A[j] * A[j]) {
                ans.push_back(A[i] * A[i]);
                --i;
            }
            else {
                ans.push_back(A[j] * A[j]);
                ++j;
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> num;
    vector<int> num2;
    num.push_back(-4);
    num.push_back(-1);
    num.push_back(0);
    num.push_back(3);
    num.push_back(10);

    s.printfVec(num);
    num2 = s.sortedSquares(num);

    s.printfVec(num2);

    return 0;
}