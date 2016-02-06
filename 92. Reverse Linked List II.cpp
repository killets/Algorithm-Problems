//别人算法差不多，但循环里面就包含了衔接三段，实际隔不了多少，因为衔接是循环外面，只执行一次
//我的for循环意思是，每次把q反转指向前一个，q是灵魂，q下次移动一位。for完了，剩下三段，最后衔接一下。
//  -----。->。(q)-
//变为 -----。<-。(q)-
//思路图 https://drive.google.com/open?id=0B0BJAgFiD4jIX253bnI1UzNBNEE

//就是画图，变指针，移动指针

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        //special case
        if(m==n) return head;
        ListNode dump(0); dump.next = head; //建立一个假节点指向head
        
        ListNode* preM = &dump;
        for(int i=1; i<m; ++i)
            preM = preM->next;
        
        ListNode* M = preM->next;
        
        ListNode* p=preM->next;
        ListNode* q = p->next;
        
        for(int i=m; i<n; ++i){
            ListNode* tmp = q->next;
            q->next = p;
            p= q;
            q = tmp;
        }
        
        preM->next = p;
        M->next=q;
        
        return dump.next;
    }
};
