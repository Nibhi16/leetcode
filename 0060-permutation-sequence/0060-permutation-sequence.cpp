class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        vector<int> fact(n, 1);
        
        // prepare numbers from 1 to n
        for (int i = 0; i < n; i++) {
            nums.push_back(i + 1);
        }
        
        // compute factorials
        for (int i = 1; i < n; i++) {
            fact[i] = fact[i - 1] * i;
        }
        
        k--; // convert to 0-based index
        string ans = "";
        
        for (int i = n; i >= 1; i--) {
            int index = k / fact[i - 1];
            ans += to_string(nums[index]);
            nums.erase(nums.begin() + index);
            k %= fact[i - 1];
        }
        
        return ans;
    }
};
