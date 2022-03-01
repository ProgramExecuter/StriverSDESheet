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
    ListNode* reverseList(ListNode* head) {
        
        ListNode *prev = NULL, *curr = head;
        while(curr) {
            // Save next NODE
            ListNode* nxt = curr->next;
            // Reverse Links
            curr->next = prev;
            // Save PREV for next node
            prev = curr;
            // Move ahead
            curr = nxt;
        }
        head = prev;
        
        return head;
    }
};