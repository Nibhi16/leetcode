class Solution {
public:
    int limit;
    unordered_map<int, int> mp;

    Solution(int n, vector<int>& blacklist) {
        int m = blacklist.size();
        limit = n - m;

        unordered_set<int> blackSet(blacklist.begin(), blacklist.end());

        // Candidates in upper range
        int next = limit;

        for (int b : blacklist) {
            // Only need to remap if b is in range [0, limit-1]
            if (b < limit) {
                // Move next forward until we find a non-blacklisted number
                while (blackSet.count(next)) 
                    next++;
                
                mp[b] = next;
                next++;
            }
        }
    }

    int pick() {
        int x = rand() % limit;
        // if x is blacklisted, return mapped value
        if (mp.count(x)) return mp[x];
        return x;
    }
};
