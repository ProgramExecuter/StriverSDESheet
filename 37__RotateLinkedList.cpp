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
    ListNode* rotateRight(ListNode* head, int k) {
        // If 0 or 1 nodes
        // return
        if(!head || !head->next) {
            return head;
        }
        
        int len = 1;
        ListNode *fast = head, *slow = head;
        
        // We move 'fast' to k places ahead
        while(fast->next) {
            fast = fast->next;
            ++len;
        }
        
        // Module k by N
        // then find (k-1)th element from back
        k %= len;
        k = len-k;
        
        // We get the end node of new list
        while(--k) {
            slow = slow->next;
        }
        
        // 'slow' contains end of new list
        // 'fast' contains end of current list
        fast->next = head;
        head = slow->next;
        slow->next = NULL;
        
        return head;
    }
};