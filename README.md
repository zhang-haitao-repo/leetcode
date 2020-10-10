# leetcode 每日一题

## 142. 环形链表 II (中等)
题解：<br>
### 方法一：哈希表  <br>
思路与算法 <br>
一个非常直观的思路是：我们遍历链表中的每个节点，并将它记录下来；一旦遇到了此前遍历过的节点，就可以判定链表中存在环。借助哈希表可以很方便地实现。<br>
代码<br>
```c++
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode *> visited;
        while (head != nullptr) {
            if (visited.count(head)) {
                return head;
            }
            visited.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};
```
### 方法二：快慢指针 <br>
思路与算法 <br>
>我们使用两个指针，fast 与 slow。它们起始都位于链表的头部。随后，slow 指针每次向后移动一个位置，而 fast 指针向后移动两个位置。如果链表中存在环，则 fast 指针最终将再次与 slow 指针在环中相遇。 <br>
设链表中环外部分的长度为 aa。slow 指针进入环后，又走了 bb 的距离与 fast 相遇。此时，fast 指针已经走完了环的 nn 圈，因此它走过的总距离为 <br>
a+n(b+c)+b=a+(n+1)b+nca+n(b+c)+b=a+(n+1)b+nc。<br>
根据题意，任意时刻，fast 指针走过的距离都为 slow 指针的 22 倍。因此，我们有 <br>
a+(n+1)b+nc=2(a+b) => a=c+(n-1)(b+c) <br>
a+(n+1)b+nc=2(a+b)⟹a=c+(n−1)(b+c) <br>
有了 a=c+(n-1)(b+c)a=c+(n−1)(b+c) 的等量关系，我们会发现：从相遇点到入环点的距离加上 n-1n−1 圈的环长，恰好等于从链表头部到入环点的距离。
因此，当发现 slow 与 fast 相遇时，我们再额外使用一个指针 ptr。起始，它指向链表头部；随后，它和 slow 每次向后移动一个位置。最终，它们会在入环点相遇。

代码 <br>
```c++
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast != nullptr) {
            slow = slow->next;
            if (fast->next == nullptr) {
                return nullptr;
            }
            fast = fast->next->next;
            if (fast == slow) {
                ListNode *ptr = head;
                while (ptr != slow) {
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
        }
        return nullptr;
    }
};
```

======================================================= <br>
```
git init 
git add README.md
git commit -m "first commit" 
git remote add origin https://github.com/zht2649825643/leetcode.git 
git push -u origin master 
```
