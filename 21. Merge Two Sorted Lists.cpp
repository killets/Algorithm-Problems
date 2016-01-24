//别人算法用recursive来做，可能导致stack overflow.

// double pointers to compare, then move forward,
// similar to Merge two vectors, merge sort

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * p = l1;
        ListNode * q = l2;
        ListNode * head = new ListNode(0);
        ListNode * cur = head;
        while(p && q) {
            if(p->val < q->val){
                cur->next = new ListNode(p->val);
                p = p->next;
                cur = cur->next;
            }
            else {
                cur->next = new ListNode(q->val);
                q = q->next;
                cur = cur->next;
            }
        }
        
        while(p) {
            cur->next = new ListNode(p->val);
            p= p->next;
            cur = cur->next;
        }
        
        while(q) {
            cur->next = new ListNode(q->val);
            q = q->next;
            cur = cur->next;
        }
        
        return head->next;
    }
};
