//别人算法很简洁，原因是设置了两个dump节点分别领导两段，然后onepass朝各段add节点，最后衔接一下即可
//我的思路相当，但是没有设置额外的假节点，因此需要维护两段的head节点，然后还要自己做判断这两段head是否为空,所以多出来很多操作

// test case [2,1]x=0,1,2,3 [2,1,1,2,3] x=2

// 问题出在没有保留和target相等元素的位置 [1,1] 1

//my idea is use three pointers to partition into three parts,
// less, equal, greater, iter through the list, add the elment into its right parts,
// then merge them together
// every parts have two pointers, (p_head, ...p), p is end, and new element<target, will
// add to p->next;

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
    ListNode* partition(ListNode* head, int x) {
     if(head==nullptr) return head;

     ListNode* p = nullptr;
     ListNode* q =nullptr;
     ListNode*p_head = nullptr;
     ListNode*q_head = nullptr;

     // add element to the end of right part(<, =, >)
     ListNode* it = head;
     while(it){
         if(it->val<x) //<
         {
             if(p_head==nullptr){
                 p_head=it;
                 p=p_head;
             } else{
                 p->next = it;
                 p = it;
             }
         } else { //=
                if(q_head==nullptr){
                    q_head = it;
                    q = q_head;
                } else{
                    q->next = it;
                    q=it;
                }
         } 
         it = it->next;
     }

     if(p&&p!=q_head&&q_head)
        p->next = q_head;

        if(q) q->next =nullptr;
        else p->next = nullptr;
    
    return p_head?p_head:q_head;
    }
};



// -----------------------------------------------------------
// 理解题意了，首先以为是第x个是target，然后以为是要分三段，实际上》=不区分
// 问题出在没有保留和target相等元素的位置 [1,1] 1

//my idea is use three pointers to partition into three parts,
// less, equal, greater, iter through the list, add the elment into its right parts,
// then merge them together
// every parts have two pointers, (p_head, ...p), p is end, and new element<target, will
// add to p->next;

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
    ListNode* partition(ListNode* head, int x) {
     if(head==nullptr) return head;

     ListNode* p = nullptr;
     ListNode* q =nullptr;
     ListNode* r = nullptr;
     ListNode*p_head = nullptr;
     ListNode*q_head = nullptr;
     ListNode*r_head = nullptr;

     // add element to the end of right part(<, =, >)
     ListNode* it = head;
     while(it){
         if(it->val<x) //<
         {
             if(p_head==nullptr){
                 p_head=it;
                 p=p_head;
             } else{
                 p->next = it;
                 p = it;
             }
         } else if(it->val ==  x){ //=
                if(q_head==nullptr){
                    q_head = it;
                    q = q_head;
                } else{
                    q->next = it;
                    q=it;
                }
         } else{ //>
             if(r_head==nullptr){
                 r_head=it;
                 r=r_head;
             } else{
                 r->next = it;
                 r=it;
             }
         }
         it = it->next;
     }

     if(p&&p!=q_head&&q_head)
        p->next = q_head;
     if(q&&q!=r_head&&r_head)
        q->next = r_head;

    if(r) r->next = nullptr;
    else{
        if(q) q->next =nullptr;
        else p->next = nullptr;
    }
    return p_head?p_head:(q_head?q_head:r_head);
    }
};
