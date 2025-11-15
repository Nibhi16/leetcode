#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    string word = "";
};

class Solution {
    TrieNode* root = new TrieNode();
    
    void insert(const string &word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children.count(c)) node->children[c] = new TrieNode();
            node = node->children[c];
        }
        node->word = word; // store complete word at end
    }
    
    void dfs(vector<vector<char>> &board, int r, int c, TrieNode* node, vector<string> &res) {
        char ch = board[r][c];
        if (!node->children.count(ch)) return;
        
        node = node->children[ch];
        if (!node->word.empty()) {
            res.push_back(node->word);
            node->word = ""; // avoid duplicates
        }
        
        board[r][c] = '#'; // mark visited
        vector<pair<int,int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
        for (auto [dr,dc] : dirs) {
            int nr = r + dr, nc = c + dc;
            if (nr >= 0 && nr < board.size() && nc >= 0 && nc < board[0].size() && board[nr][nc] != '#') {
                dfs(board, nr, nc, node, res);
            }
        }
        board[r][c] = ch; // backtrack
    }
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (auto &w : words) insert(w);
        vector<string> res;
        for (int r = 0; r < board.size(); r++)
            for (int c = 0; c < board[0].size(); c++)
                dfs(board, r, c, root, res);
        return res;
    }
};
