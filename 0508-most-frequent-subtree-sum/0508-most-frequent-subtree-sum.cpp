class Solution {
public:
    unordered_map<int,int> mp;

    int dfs(TreeNode* root) {
        if (!root) return 0;
        int sum = root->val + dfs(root->left) + dfs(root->right);
        mp[sum]++;
        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        if (!root) return {};
        dfs(root);

        int mx = 0;
        for (auto &p : mp) mx = max(mx, p.second);

        vector<int> ans;
        for (auto &p : mp) {
            if (p.second == mx) ans.push_back(p.first);
        }
        return ans;
    }
};
