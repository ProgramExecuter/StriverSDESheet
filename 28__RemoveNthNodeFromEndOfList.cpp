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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head;
        
        // Move 'fast' pointer N steps ahead
        while(n--) {
            fast = fast->next;
        }
        
        // Useful for storing HEAD
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* slow = dummy;
        
        while(fast) {
            fast = fast->next;
            slow = slow->next;
        }
        
        ListNode* del = slow->next;
        slow->next = slow->next->next;
        
        delete del;
        
        return dummy->next;
    }
};