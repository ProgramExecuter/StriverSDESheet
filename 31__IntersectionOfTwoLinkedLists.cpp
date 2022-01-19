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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *l1 = headA, *l2 = headB;
        
        bool onceA = false, onceB = false;
        
        while(l1 != l2) {
            // If the 'l1' reached its end
            // then continue from head of 'l2'
            if(l1->next == NULL) {
                if(onceA) break;
                onceA = true;
                l1 = headB;
            }
            else {
                l1 = l1->next;
            }
            
            // If the 'l2' reached its end
            // then continue from head of 'l1'
            if(l2->next == NULL) {
                if(onceB)   break;
                onceB = true;
                l2 = headA;
            }
            else {
                l2 = l2->next;
            }
        }
        
        if(l1 != l2)    return NULL;
        
        return l1;
    }
};