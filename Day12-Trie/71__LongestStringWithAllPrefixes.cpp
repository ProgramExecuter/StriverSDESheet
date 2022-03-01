class TrieNode {
public:
    TrieNode *arr[26];
    bool flag = false;
    
    bool containsChar(char ch) {
        return arr[ch-'a'] != NULL;
    }
    
    TrieNode* get(char ch) {
        return arr[ch-'a'];
    }
    
    void set(char ch, TrieNode* node) {
        arr[ch-'a'] = node;
    }
    
    void setEnd() {
        flag = true;
    }
    
    bool isEnd() {
        return flag;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* tmp = root;
        
        for(char ch : word) {
            // If it doesn't contain this character
            // then create a new TrieNode
            if(tmp->containsChar(ch) == false) {
                tmp->set(ch, new TrieNode());
            }
            
            // Move to next Node
            tmp = tmp->get(ch);
        }
        
        // Set this word as ended
        tmp->setEnd();
    }
    
    bool isComplete(string word) {
        TrieNode* tmp = root;
        
        for(char ch : word) {
            // Move to next Node
            tmp = tmp->get(ch);
            
            // If this is end, then this prefix is also present
            if(tmp->isEnd() == false)
                return false;
        }
        return true;
    }
};

bool util(string a, string b) {
    if(a.size() < b.size())
        return true;
    return false;
}
string completeString(int n, vector<string> &a) {
    // So that we start from biggest string
    sort(a.begin(), a.end(), util);
    reverse(a.begin(), a.end());
    
    Trie *t = new Trie();
    
    // Insert all the strings in Trie
    for(string s : a) {
        t->insert(s);
    }
    
    // Find the complete word
    for(string s : a) {
        if(t->isComplete(s)) {
            return s;
        }
    }
    return "None";
}