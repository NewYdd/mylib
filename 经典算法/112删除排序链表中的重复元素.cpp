112. 删除排序链表中的重复元素
给定一个排序链表，删除所有重复的元素每个元素只留下一个。

样例
给出 1->1->2->null，返回 1->2->null

给出 1->1->2->3->3->null，返回 1->2->3->null
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

class Solution {
public:
    /**
     * @param head: head is the head of the linked list
     * @return: head of linked list
     */
    ListNode * deleteDuplicates(ListNode * head) {
        if(head==NULL || head->next==NULL)
            return head; 
         ListNode *p = head->next;
    	 ListNode *q = head;
    
    	 while (p != NULL)
    	 {
    		 if (p->val == q->val)
    		 {
    			 q->next = p->next;
    			 delete p;
    			 p = q->next;
    			 
    		 }
       		 else
    		 {
    		     q = q->next;
            	 p = p->next;
    		     
    		 }
    	 }
    	 return head;
      
    }
};