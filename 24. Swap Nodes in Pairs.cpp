//别人算法用recursive的方法，写起来很简单，不用考虑非常复杂的操作，但空间是o(n),不是o(1) 
//递归图:https://drive.google.com/file/d/0B0BJAgFiD4jITkVxUG1KYzZtSmM/view?usp=sharing
//别人c++算法（2nd）相当于把31,32,33三行判断和赋值放到了while的初始化中去，值得学习。

// basic idea is pointer manipulation
// use two pointers, left point to first element, right point to next, only when right is valid,
// we have 2 nodes and can swap a pair.
// basic operations can link a pair node to its right follows, but can not edit its precedent ones,
// so use a pointer to pointer to remember last place.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr) return head;
        ListNode* left = head;
        ListNode* right = head->next;
        ListNode** p = &head;
        while(right) {
            left->next = right->next;
            right->next = left;
            (*p) = right;  // first run: head = right
            p=&(left->next); // new 'head' point to next pair;
            left=left->next;  // Note! other people put below codes into while()
            if(left==nullptr) break; //Note!
            right= left->next;
        }
        return head;
    }
};
