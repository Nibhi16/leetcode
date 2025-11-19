class Solution {
public:
    unordered_map<string, bool> dp;

    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;
        if (s1.size() != s2.size()) return false;

        string key = s1 + "|" + s2;
        if (dp.count(key)) return dp[key];

        int n = s1.size();

        // Prune: if char counts differ → impossible
        string a = s1, b = s2;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if (a != b) return dp[key] = false;

        // Try all possible partitions
        for (int i = 1; i < n; i++) {
            // Case 1: No swap
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                isScramble(s1.substr(i), s2.substr(i)))
                return dp[key] = true;

            // Case 2: Swap happened
            if (isScramble(s1.substr(0, i), s2.substr(n - i)) &&
                isScramble(s1.substr(i), s2.substr(0, n - i)))
                return dp[key] = true;
        }

        return dp[key] = false;
    }
};
