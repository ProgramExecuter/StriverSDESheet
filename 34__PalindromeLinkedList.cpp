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
    bool isPalin(ListNode* &left, ListNode* right) {
        // Reached end of list for right
        if(right == NULL) {
            return true;
        }
        
        // If any of pair of nodes return false
        // then recursively return 'false'
        bool flag = isPalin(left, right->next);
        if(!flag) {
            return false;
        }
        
        // Check if two elements are same
        bool ans = ( left->val  ==  right->val );
        
        // move left pointer
        left = left->next;
        
        return ans;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *left = head, *right = head;
        return isPalin(left, right);
    }
};