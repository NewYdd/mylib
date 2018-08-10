/**
 * Definition of singly-linked-list:
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */


174. 删除链表中倒数第n个节点
给定一个链表，删除链表中倒数第n个节点，返回链表的头节点。
 
 class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param n: An integer
     * @return: The head of linked list.
     */
    ListNode * removeNthFromEnd(ListNode * head, int n) {
         int size = 0;
    	 ListNode * p = head,*q;
    	 while (p)
    	 {
    		 p = p->next;
    		 size++;
    	 }
    	 
    	 p = head;
    	 int index = size-n;
    	 if (index < 0)
    		 return head;
         if (index == 0)
    	 {
    		 q = head;
    		 head = head->next;
    		 delete q;
    		 return head;
    	 }
    	 for (int i = 0; i < index-1; i++)
    		 p = p->next;
    
    	 q = p->next;
    	 p->next = q->next;
    	 delete q;
    	 return head;
    }
};

注意考虑删除头节点