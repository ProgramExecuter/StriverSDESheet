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
    bool hasCycle(ListNode *head) {
        // If 0 or 1 nodes present
        if(!head || !head->next)
            return false;
        
        ListNode *fast = head;
        ListNode *slow = head;
        
        // When slow and fast meet, there is a cycle
        do {
            fast = fast->next->next;
            slow = slow->next;
        } while(fast && fast->next && fast != slow);
        
        if(fast!=NULL && fast->next!=NULL)
            return true;
        
        return false;
    }
};