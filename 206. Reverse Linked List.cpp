//别人算法同理，且还有recursive的算法，这个是亮点
//同92. Reverse Linked List II 而且不用衔接了，更简单.每次反一个节点，最后改改head->next
//解法:画指针图
//test case :[] [1] [1,2,3]
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
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr||head->next==nullptr) return head;
        ListNode* pre_p = head;
        ListNode* p = head->next;
        while(p){
            ListNode* tmp = p->next;
            p->next = pre_p;
            pre_p = p;
            p= tmp;
        }
        head->next = nullptr;
        return pre_p;
    }
};
