Given head, the head of a linked list, determine if the 
linked list has a cycle in it.

There is a cycle in a linked list if there is some node 
in the list that can be reached again by continuously 
following the next pointer. Internally, pos is used to 
denote the index of the node that tail's next pointer is 
connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. 
Otherwise, return false.

//code
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
#include <unordered_set>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> s;
        for (; head; head = head->next) {
            if (s.find(head) != s.end()) {
                return true;
            }
            s.insert(head);
        }
        return false;
    }
};

int main() {
    // Create a linked list: 3 -> 2 -> 0 -> -4 -> 2 (cycle)
    ListNode* head = new ListNode(3);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(0);
    ListNode* fourth = new ListNode(-4);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = second; // Create a cycle

    Solution solution;
    bool result = solution.hasCycle(head);
    cout << "The linked list has a cycle: " << (result ? "Yes" : "No") << endl;

    // Clean up memory (in a real scenario, you would need to handle this carefully due to the cycle)
    delete head;
    delete second;
    delete third;
    delete fourth;

    return 0;
}