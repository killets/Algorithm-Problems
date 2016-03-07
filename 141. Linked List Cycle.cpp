//别人算法是一样的，小差别是开头fast=head，然后最后return false

// typical two pointers, if they meet, there is a cycle
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
    bool hasCycle(ListNode *head) {
        if(head==nullptr) return false;
        ListNode * slow = head;
        ListNode * fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
            return true;
        }
        
        return (slow==fast);
    }
};
