//我算法比别人好在但k<length时，不用去走完全部list判断list的长度

//wrong answer [1,2,3] 4 [3,1,2] 这里我开始以为k超过list长度就直接返回原list。但提示wrong answer，
// 分析它的答案知k实际上效果是 k%length;

// two pointers 先走开gap，然后再走，定位到目的位置

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr) return head;
        
        ListNode* left = head;
        ListNode* right = head;
        int cnt = k;
        while(cnt--){
            right=right->next;
            if(right==nullptr){ // k >= list length
                right = head;       // 回头重来
                cnt = k%(k-cnt);  // fix wrong answer 
                if(cnt==0)
                return head; // nothing change
            }
           
        }
        
        while(right->next){
            right = right->next;
            left = left->next;
        }
        // 1->2->3->4->5->NULL and k = 2
        //       |l    |r
        right->next = head;
        head = left->next;
        left->next = nullptr;
        
        return head;
    }
};
