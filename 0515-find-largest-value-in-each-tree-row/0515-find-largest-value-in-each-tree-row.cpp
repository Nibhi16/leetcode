class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};

        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;

        while (!q.empty()) {
            int sz = q.size();
            int mx = INT_MIN;

            while (sz--) {
                auto node = q.front(); q.pop();
                mx = max(mx, node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            ans.push_back(mx);
        }
        return ans;
    }
};
