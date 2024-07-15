You are given an array of k linked-lists lists, 
each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list 
and return it.

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

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return NULL;
        return mergeKLists(lists,0,lists.size()-1);
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists, int start, int end){
        if(start == end)
            return lists[start];
        
        int mid = start + (end-start)/2;
        ListNode* left = mergeKLists(lists,start,mid);
        ListNode* right = mergeKLists(lists,mid+1,end);
        
        return mergeTwoLists(left,right);
    }
    
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
};