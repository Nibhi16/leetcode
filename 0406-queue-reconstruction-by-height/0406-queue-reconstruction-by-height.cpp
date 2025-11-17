class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // Sort: height desc, k asc
        sort(people.begin(), people.end(), [](auto &a, auto &b) {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] > b[0];
        });

        vector<vector<int>> result;
        for (auto &p : people) {
            result.insert(result.begin() + p[1], p);
        }
        return result;
    }
};
