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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return nullptr;
        
        ListNode *f = head, *s = head;
        while (s != nullptr && f != nullptr && f->next != nullptr) {
            s = s->next;
            f = f->next->next;
            if(s == f)  break;
        }

        // If S and F didn't meet then no cycle
        if(s != f)
            return nullptr;
        
        // Where S and F meet again is the start of loop
        s = head;
        while (s != f) {
            s = s->next;
            f = f->next;
        }
        
        return s;
    }
};