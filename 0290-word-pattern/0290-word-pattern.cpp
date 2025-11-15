#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream ss(s);
        string word;
        while (ss >> word) words.push_back(word);

        if (pattern.size() != words.size()) return false;

        unordered_map<char, string> p2w;
        unordered_map<string, char> w2p;

        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string w = words[i];

            if ((p2w.count(c) && p2w[c] != w) || 
                (w2p.count(w) && w2p[w] != c))
                return false;

            p2w[c] = w;
            w2p[w] = c;
        }

        return true;
    }
};
