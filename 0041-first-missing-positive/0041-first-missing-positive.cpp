class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Place each number in its "correct" position: nums[i] = i+1
        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i]-1] != nums[i]) {
                swap(nums[i], nums[nums[i]-1]);
            }
        }

        // Find first position where nums[i] != i+1
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) return i + 1;
        }

        return n + 1; // all numbers 1..n are present
    }
};