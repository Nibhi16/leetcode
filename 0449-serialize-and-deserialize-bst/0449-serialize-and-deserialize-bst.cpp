class Codec {
public:
    // Serialize BST using preorder traversal
    string serialize(TreeNode* root) {
        string data;
        preorder(root, data);
        return data;
    }

    // Deserialize string back to BST
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        stringstream ss(data);
        vector<int> values;
        string temp;

        while (getline(ss, temp, ',')) {
            if (temp.size() > 0)
                values.push_back(stoi(temp));
        }

        int index = 0;
        return build(values, index, INT_MIN, INT_MAX);
    }

private:
    // Preorder traversal
    void preorder(TreeNode* root, string &data) {
        if (!root) return;
        data += to_string(root->val) + ",";
        preorder(root->left, data);
        preorder(root->right, data);
    }

    // Rebuild using value bounds
    TreeNode* build(vector<int>& vals, int &idx, int low, int high) {
        if (idx >= vals.size()) return nullptr;

        int val = vals[idx];
        if (val < low || val > high) return nullptr;

        TreeNode* node = new TreeNode(val);
        idx++;

        node->left = build(vals, idx, low, val);
        node->right = build(vals, idx, val, high);

        return node;
    }
};
