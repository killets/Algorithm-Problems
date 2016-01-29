//别人算法思想是，将要删除的结点的下一个节点内容复制到当前要删除的节点；
//这样，物理地址没有变，内容变了，val和next，同时原来的下一个节点就冗余了
//相当于两个节点(内容一样)都指向原来的下下一个节点
// 
//    toRemove->next->next2 变为
//    next      next->next2
       |----------------|
//实际这个物理节点是不可能被删除的（除非它是head），因为无法回退一步修改前一节点
// 的next域的值

// my idea is not actually delete that real node,
// but change its value to its next node;
// I mean that is to shift all right values one step left

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
    void deleteNode(ListNode* node) {
        
        ListNode* p=node;
        while(p->next->next){ // since we need to set p->next=null, 
                              //we can't change its left element's next pointer
            p->val=p->next->val;
            p=p->next;
        }
        p->val=p->next->val;
        p->next=nullptr;
    }
};
