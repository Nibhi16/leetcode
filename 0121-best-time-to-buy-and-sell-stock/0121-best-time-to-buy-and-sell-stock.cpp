class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int max_profit=0;
      int n=prices.size();
      int left=0;
      int right=1;
      while(right<n){
        if(prices[right]>prices[left]){
            int profit= prices[right]-prices[left];
            max_profit= max(profit, max_profit);
        }
        else{
            left=right;
        }
        right++;
      }
      return max_profit;
      
      }
};