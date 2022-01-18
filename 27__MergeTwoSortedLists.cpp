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
    void util(ListNode* &tmp, ListNode* &curr) {
        tmp->next = curr;
        curr = curr->next;
        tmp = tmp->next;
    }
    bool isValid(ListNode* curr1, ListNode* curr2) {
        bool ans = curr1 && curr2;
        return ans;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy = new ListNode(0);
        ListNode *tmp = dummy, *curr1 = list1, *curr2 = list2;
        
        while(isValid(curr1, curr2)) {
            // Link List1 until its data is lesser than list2's node
            while(isValid(curr1, curr2)  &&  curr1->val < curr2->val) {
                util(tmp, curr1);
            }
            
            // Link List2 until its data is lesser than list1's node
            while(isValid(curr1, curr2)  &&  curr2->val <= curr1->val) {
                util(tmp, curr2);
            }
        }
        
        // Remaining Nodes of List1 or List2
        ListNode* rem = curr1 == NULL ? curr2 : curr1;
        while(rem) {
            util(tmp, rem);
        }
        
        return dummy->next;
    }
};