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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // If only 1 node or k = 1
        // No need for any operation
        if (k == 1 || !head->next) {
            return head;
        }
        
        ListNode *prevLink, *curr, *prev = NULL, *tmp, *next;
        curr = head;
        prevLink = curr;
        
        // First K nodes reverse
        int n = k;
        while(curr && n--) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        
        while(curr) {
            n = k;
            prev = NULL;
            
            // Check if no. of nodes >= k
            tmp = curr;
            while(tmp && --n) {
                tmp = tmp->next;
            }
            // No. of nodes < k
            if(tmp == NULL) {
                prevLink->next = curr;
                break;
            }
            
            // Reverse K nodes
            tmp = curr;
            n = k;
            while(curr && n--) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            // Link prev K Node group's first Node
            // to this K Node group's last Node
            prevLink->next = prev;
            prevLink = tmp;
            curr = next;
        }
        
        return head;
    }
};