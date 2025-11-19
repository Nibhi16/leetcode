class Solution {
public:
    // Get max subsequence of length k using a monotonic stack
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> stack;
        int drop = nums.size() - k;
        
        for (int num : nums) {
            while (!stack.empty() && drop > 0 && stack.back() < num) {
                stack.pop_back();
                drop--;
            }
            stack.push_back(num);
        }
        
        stack.resize(k);
        return stack;
    }

    // Merge two subsequences into the maximum lexicographical sequence
    vector<int> merge(vector<int> a, vector<int> b) {
        vector<int> res;
        while (!a.empty() || !b.empty()) {
            if (a > b) {
                res.push_back(a[0]);
                a.erase(a.begin());
            } else {
                res.push_back(b[0]);
                b.erase(b.begin());
            }
        }
        return res;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> best(k, 0);

        int n1 = nums1.size(), n2 = nums2.size();

        // Try all splits
        for (int i = max(0, k - n2); i <= min(k, n1); i++) {
            vector<int> p1 = maxSubsequence(nums1, i);
            vector<int> p2 = maxSubsequence(nums2, k - i);
            vector<int> candidate = merge(p1, p2);

            best = max(best, candidate);
        }
        return best;
    }
};
