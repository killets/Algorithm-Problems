//我算法慢在，每次都要从头开始数插入位置。别人快在分步的第二步将其倒序一次，后面就直接相当于我想的两个队列拼成一个队列了
//找中间点的想法是对的
//：You are here! Your runtime beats 0.31% of cppsubmissions.
// something like a stack, do n-2 first, l2:ln-2; then l1:ln-1; then back l0:ln
//或者从ln开始安排，然后ln-1
//以上分析后，决定1st try: 切成两段，然后把第二段元素依次朝第一段中插入，第一段倒着来数，注意总个数分奇偶两种情况
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
    void reorderList(ListNode* head) {
        if(head == nullptr ||head->next == nullptr) return;
        ListNode* slow = head;
        ListNode* fast = head;
        
        int cnt = 0;
        while(fast&&fast->next){
            slow = slow->next;
            fast = fast->next->next;
            cnt++;
        }
     
        ListNode* p = slow->next;
        slow->next = nullptr;
        int sum = fast?cnt+1:cnt; //NOTE: 1,2,3,4,5,6,7,8 [1,8,2,7,3,6,4,5] is different with 1,2,3,4,5,6,7 [1,7,2,6,3,5]
        for(int i=0; i<cnt && p; i++){
            ListNode* slow = head;
            int j=1;
            while(j!=sum-(2*i+1)){
                slow = slow->next;
                j++;
            }
            ListNode* tmp = p->next;
            p->next = slow->next;
            slow->next = p;
            p = tmp;
            sum++;
        }
    }
};
