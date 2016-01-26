// 别人算法，是考虑不回头看，但x=x->next时，x->next等于以（x->next）为头的
// 相同问题中的下一个不重复的元素；使用recursive way，见comments

// 1 double pointer, left and right, 
// sorted array, 找重复回头看，因为要保住第一个
// left 到right之间的都是重复元素，当找到下一个不重复时，
// left->next=right

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr) return head;
         ListNode* left = head;
         ListNode* right = head->next;
        while(right) {
            if(right->val==left->val) {
                right=right->next;
            } else{
                // delete left->next; if(left->next!=right) delete left->next,next...
                left->next=right;
                left=right;
                right=right->next;
            }
        }
        left->next=nullptr; //Note!
        
        return head;
    }
};
