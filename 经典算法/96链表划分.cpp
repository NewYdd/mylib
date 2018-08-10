96. 链表划分
给定一个单链表和数值x，划分链表使得所有小于x的节点排在大于等于x的节点之前。

你应该保留两部分内链表节点原有的相对顺序。
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
     * @param head: The first node of linked list
     * @param x: An integer
     * @return: A ListNode
     */
 ListNode * partition(ListNode * head, int x) {
        
        if(head==NULL)    //如果是空链表，返回空
            return NULL;
            
        ListNode *small=new ListNode(0);         //小列表的假表头
        //这个假表头应该是实体，因为操作的是它的next，如果本身就是空的，那么操作next就会出错。
        ListNode *small_back;   //最后一节点
        ListNode *big=new ListNode(0);           //大列表的假表头
        ListNode *big_back;     //最后一个节点
        
        ListNode *tmp=NULL;
        
        while(head)         
        {
            tmp=head;
            
            head=head->next;   //HEAD被tmp接管,head后移
            
            tmp->next=NULL;
            
            if(tmp->val<x)
            {
                if(!small->next)  //还是空的
                {
                    small->next=tmp;   //第一个接上来
                    small_back=small->next;   //后移
                }
                else
                {
                    small_back->next=tmp;
                    small_back=small_back->next;

                }
            }
            else
            {
                if(!big->next)
                {
                    big->next=tmp;
                    big_back=big->next;
                }
                else
                {
                    big_back->next=tmp;
                    big_back=big_back->next;

                }
            }
            
        }
        if(!small->next)   return big->next;    
        if(!big->next)    return small->next;
        small_back->next=big->next;
        return small->next;
    }
           

};