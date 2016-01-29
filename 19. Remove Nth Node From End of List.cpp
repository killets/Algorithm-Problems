//别人算法的思想是一致的，值得学习的是slow pointer 用了pointer to pointer 指向 head;
//这样就起始状态slow指向的就是head之前，一定能保证slow在后面不管是不是删head都指向
//要删的元素之前

// my idea is use two pointers, their distance is n;
// when fast pointer reach before end of list, slow->next is exactly
// which one we want to remove

//     n=2
//     slow fast
//      |   |
//list: - - - 

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       // slow pointer is point to the one before we want to remove
       ListNode* slow=head;
       ListNode* fast=head;
       while(n--){ // 注意不是--n
           fast=fast->next;
           if(fast==nullptr){ //this case is to remove head
               return head->next;
           }
       }
       // fast is not reaching end, so we can move forward both
       // fast and slow pointer
       while(fast->next){ //注意不是fast
           fast=fast->next;
           slow=slow->next;
       }
       slow->next=slow->next->next;
       return head;
    }
};
