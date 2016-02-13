//别人算法也差不多，都是找到重复段，然后要记住重复段前面的那个，再跳过重复段，然后衔接前后，如果最后是重复的，记得设置left的next为空。

// two pointers, remember what duplicate is ,then go over all this value
// what is not that good is left -> next = right is excued every move 
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
        ListNode dump(0);
        dump.next= head;
        ListNode * left = &dump;
        ListNode * right = head;
        
        while(right){
            
            if(right->next && right->val==right->next->val){
                int v = right->val;
                while(right && right->val == v)
                    right= right->next;
                    
                
            } else{
                left -> next = right;
                left = right;
                right = right->next;
            }
        }
        
        if(left->next) left->next = nullptr; //#1 special case [1 1 1 2 3  3 4 4 ]
        
        return dump.next;
    }
};
