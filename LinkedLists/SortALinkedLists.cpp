Given the head of a linked list, return the list 
after sorting it in ascending order.

//code

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        
        if(list1->val <= list2->val){
            list1->next = mergeTwoLists(list1->next,list2);
            return list1;
        }
        else {
            list2->next = mergeTwoLists(list1,list2->next);
            return list2;
        }
        
    }
    ListNode* sortList(ListNode* head) {
        
        if(!head || !head->next)
            return head;
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prev->next = NULL;
        
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);
        
        return mergeTwoLists(left,right);
    }
};