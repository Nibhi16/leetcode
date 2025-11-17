class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        int result = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<long long, int> freq;

            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                long long dx = points[i][0] - points[j][0];
                long long dy = points[i][1] - points[j][1];
                long long dist = dx * dx + dy * dy;

                freq[dist]++;
            }

            for (auto &p : freq) {
                int f = p.second;
                result += f * (f - 1);   // permutations
            }
        }

        return result;
    }
};
