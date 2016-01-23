// 别人算法，值得借鉴的是，return head->next;
// while() idea is from addBinary

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * head = nullptr;
        ListNode * p = nullptr; // current node
        bool carry = 0;
       
        while(l1 || l2 || carry) {
            int sum = 0;
            if(l1) {sum += l1->val; l1 = l1->next;}
            if(l2) {sum += l2->val; l2 = l2->next;}
            sum += carry;
            if(sum > 9) {
                sum = sum -10;
                carry = true;
            }else {
                carry = false;
            }
            if(head==nullptr) {head = new ListNode(sum); p= head;}
            else {p->next = new ListNode(sum); p= p->next;}
        }
        
        return head;
    }
};
