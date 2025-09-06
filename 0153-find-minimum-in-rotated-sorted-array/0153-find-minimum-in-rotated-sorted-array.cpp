class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int ans = nums[0];
        for(int i=1;i<n;i++){
            ans = min(ans, nums[i]);
        }
        return ans;
    }
};