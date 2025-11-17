class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size();
        int m = key.size();

        // Store all positions of each character in ring
        vector<vector<int>> pos(26);
        for (int i = 0; i < n; i++) {
            pos[ring[i] - 'a'].push_back(i);
        }

        // Memo table
        vector<vector<int>> dp(n, vector<int>(m, -1));

        function<int(int,int)> solve = [&](int ringPos, int keyIdx) {
            if (keyIdx == m) return 0;
            if (dp[ringPos][keyIdx] != -1) return dp[ringPos][keyIdx];

            int ans = INT_MAX;
            char target = key[keyIdx];

            // Try every same character in the ring
            for (int p : pos[target - 'a']) {
                int diff = abs(ringPos - p);
                int step = min(diff, (int)ring.size() - diff);  // circular

                ans = min(ans, step + 1 + solve(p, keyIdx + 1));
            }

            return dp[ringPos][keyIdx] = ans;
        };

        return solve(0, 0);
    }
};
