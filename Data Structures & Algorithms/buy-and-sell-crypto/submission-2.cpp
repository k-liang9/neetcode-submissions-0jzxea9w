class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }
        int left = 0;
        int right = 1;
        int max_profit = 0;
        while (right < prices.size()) {
            if (prices[right] < prices[left]) {
                left = right;
            } else {
                max_profit = max(max_profit, prices[right] - prices[left]);
            }
            right++;
        }
        return max_profit;
    }
};
