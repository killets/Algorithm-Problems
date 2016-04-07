//使用merge sort，在array中需要额外空间，在list中不需要

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 //2 try pointers method instead of size method
 //1 accepted, use MergeSort, and size parameters in merge fnc (64ms)
 
class Solution {
private:
	// two ways: 1) use 4 pointers, 2) use 2 ptrs and 2 size parameters
	void  merge(ListNode* & f1, ListNode* & last1, ListNode* & f2, ListNode* & last2, int size1){

		ListNode * head;
		ListNode * tail;
		auto it1 = f1;
		auto it2 = f2;
		//update f1: newhead
		if (f1->val > f2->val){
			head = f2;
			tail = head;
			it2 = f2->next;
		}
		else{
			head = f1;
			tail = head;
			it1 = it1->next;
		}
		f1 = head;

		//merge
		while (it1 != last1->next&&it2 != last2->next){
			if (it1->val > it2->val){
				tail->next = it2;
				tail = it2;
				it2 = it2->next;
			}
			else{
				tail->next = it1;
				tail = it1;
				it1 = it1->next;
			}
		}

		if (it1 != last1->next){
			tail->next = it1;
			tail = last1;
		}
		else if (it2 != last2->next){
			tail->next = it2;
			tail = last2;
		}
		tail->next = NULL;

		//update last1,f2,last2;
		auto it = f1;
		for (int i = 1; i < size1; i++){
			it = it->next;
		}
		last1 = it;
		f2 = it->next;
		last2 = tail;

	}

	void mergesort(ListNode* & first, ListNode* & last, int size){
		if (size >= 2){
			auto ita = first;
			for (int i = 1; i<size / 2; i++){
				ita = ita->next;
			}
			auto ita2_first = ita->next;

			mergesort(first,ita, size / 2);
			mergesort(ita2_first,last, size - size / 2);

			merge(first, ita, ita2_first, last, size/2);
		}

	}


public:
	ListNode* sortList(ListNode* head) {

		if (head == NULL || head->next == NULL)
			return head;
		auto ita = head;
		int size = 1;
		while (ita->next != NULL){
			size++;
			ita = ita->next;
		}
		mergesort(head, ita, size);
		return head;
	}
};
