class WordDictionary {
public:
    struct Node {
        bool end;
        Node* children[26];

        Node() {
            end = false;
            for (int i = 0; i < 26; i++) children[i] = nullptr;
        }
    };

    Node* root;

    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx])
                curr->children[idx] = new Node();
            curr = curr->children[idx];
        }
        curr->end = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }

    bool dfs(const string &word, int index, Node* node) {
        if (!node) return false;
        
        if (index == word.size())
            return node->end;
        
        char c = word[index];
        
        if (c == '.') {  
            // Try all 26 possible children
            for (int i = 0; i < 26; i++) {
                if (dfs(word, index + 1, node->children[i]))
                    return true;
            }
            return false;
        } else {  
            // Normal character
            int idx = c - 'a';
            return dfs(word, index + 1, node->children[idx]);
        }
    }
};
