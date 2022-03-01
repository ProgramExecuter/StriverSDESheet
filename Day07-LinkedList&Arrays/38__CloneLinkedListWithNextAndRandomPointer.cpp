/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) {
            return NULL;
        }
        
        Node *tmp = head;
        
        // Insert new Nodes in between
        while(tmp) {
            Node *newNode, *nxt = tmp->next;
            
            // Create New Node
            newNode = new Node(tmp->val);
            
            // Insert the New Node after original Node
            newNode->next = tmp->next;
            tmp->next = newNode;
            
            tmp = nxt;
        }
        
        tmp = head;
        
        // Make 'random' pointers for New Nodes
        while(tmp) {
            // Make pointer to correct 'random'
            if(tmp->random == NULL)
                tmp->next->random = NULL;
            else
                tmp->next->random = tmp->random->next;
            
            tmp = tmp->next->next;
        }
        
        tmp = head;
        Node *newHead = head->next;
        
        // Get the original and new list
        while(tmp) {
            Node *nxt = tmp->next->next;
            
            // Make 'next's of New Nodes
            if(nxt)
                tmp->next->next = nxt->next;
            else
                tmp->next->next = NULL;
            
            
            // Make the original list
            tmp->next = nxt;
            tmp = nxt;
        }
        
        return newHead;
    }
};