class Solution {
public:
    bool canSplit(vector<int>& nums, int m, long long maxSum) {
        long long curr = 0;
        int count = 1;

        for (int num : nums) {
            if (curr + num > maxSum) {
                count++;
                curr = num;
                if (count > m) return false;
            } else {
                curr += num;
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int m) {
        long long low = *max_element(nums.begin(), nums.end());
        long long high = accumulate(nums.begin(), nums.end(), 0LL);
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (canSplit(nums, m, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
