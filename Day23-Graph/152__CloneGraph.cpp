// Time Complexity - O(NlogN)
// Space Complexity - O(N)

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)  return NULL;
        unordered_map<Node*, Node*> copies;           // Map copy of node -> node
        
        Node* copy = new Node(node->val, {});
        copies[node] = copy;
        
        queue<Node*> todo;
        todo.push(node);
        
        while (!todo.empty()) {
            Node* cur = todo.front();
            todo.pop();
            
            for(Node* neighbor : cur -> neighbors) {
                if(copies.find(neighbor) == copies.end()) {             // Not visited
                    copies[neighbor] = new Node(neighbor->val, {});
                    todo.push(neighbor);
                }
                
                copies[cur]->neighbors.push_back( copies[neighbor] );   // Push it as neighbor of curr node's clone
            }
        }
        
        return copy;
    }
};