//别人算法思路和我是一样的，但是实现不一样，它没有记数而是走完掉头走另一条线，这样等长的走完时，掉头到另一个开头，这个时候
//正好实现了我想要的两者对齐同步了。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //各自走一遍走到底，数下步数，算步数差，然后多的那个先走步数差使两者同步，然后同步开始走，相遇点即为交叉。
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int cnt1 =0;
        int cnt2 = 0;
        ListNode* a = headA;
        ListNode*b = headB;
        while(a){
            a=a->next;
            cnt1++;
        }
        
        while(b){
            b=b->next;
            cnt2++;
        }
        
        a = headA;
        b= headB;
        if(cnt1>cnt2){
            int dif = cnt1-cnt2;
            while(dif){
                a= a->next;
                dif--;
            }
        }else{
            int dif=cnt2-cnt1;
            while(dif){
                b=b->next;
                dif--;
            }
        }
        
        while(a!=b){
            a=a->next;
            b=b->next;
        }
        
        return a;
    }
};
