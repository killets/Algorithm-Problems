//别人算法，是当第一次相遇后，不求L什么的，fast继续走，速度改为1，slow从头开始走，速度仍然为1，这样当再次相遇时，
//刚好是圆圈起点，因为这时刚好都走了a步
//图解：https://drive.google.com/open?id=0B0BJAgFiD4jIdDItUG0xMlp0elE

 //我的想法是数数，a,b,L,然后求a；后来发现L算出来后，算不出a，但是可以重走，这次让两个指针同速度，但相隔L，当首次相遇时，即为所求。
 //感觉我的算法更好理解，别人算法比较巧。
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
    ListNode *detectCycle(ListNode *head) {
        //if(head==nullptr||head->next==nullptr) return nullptr;//可以省略
        ListNode * slow = head;
        ListNode * fast = head;
        
        while(fast&&fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){ // find cycle
                ListNode* tmp = slow;
                int L =1;
                while(tmp->next!=slow){ //cycle length
                    L++;
                    tmp = tmp->next;
                }
                if(L==1)
                    return slow;
                else {  // right ahead L of left, when they first meet, it's the begin node
                    ListNode* left =head;
                    ListNode * right = head;
                    while(L--){
                        right= right->next;
                    }
                    while(left!=right){
                        left = left->next;
                        right = right->next;
                    }
                    return left; // they meet
                }
            }
        }
        
        return nullptr;
        
        
        
    }
};
