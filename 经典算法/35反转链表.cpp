35. 翻转链表
翻转一个链表

样例
给出一个链表1->2->3->null，这个翻转后的链表为3->2->1->null

挑战
在原地一次翻转完成S

class Solution {
public:
    /**
     * @param head: n
     * @return: The new head of reversed linked list.
     */
    ListNode * reverse(ListNode * head) {
        // write your code here
         ListNode * q, *p = head;
    	 ListNode * newHead = NULL;
    
    	 while (p)
    	 {
    		 q = p->next;
    		 p->next = newHead;
    		 newHead = p;
    		 p = q;
    	 }
    	 return newHead;
    }
};