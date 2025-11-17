class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> dp;

        dp[0].insert(0);  // at stone 0 with last jump 0

        unordered_set<int> stoneSet(stones.begin(), stones.end());

        for (int stone : stones) {
            for (int k : dp[stone]) {
                for (int step : {k - 1, k, k + 1}) {
                    if (step > 0) {
                        int next = stone + step;
                        if (stoneSet.count(next)) {
                            dp[next].insert(step);
                        }
                    }
                }
            }
        }

        return !dp[stones.back()].empty();
    }
};
