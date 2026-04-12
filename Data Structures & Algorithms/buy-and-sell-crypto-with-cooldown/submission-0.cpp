class Solution {
public:

    int dp(const vector<int>& prices, vector<vector<int>>& memo, int state, int i) {
        if (i >= prices.size()) {
            return 0;
        }

        if (memo[state][i] != -1) {
            return memo[state][i];
        }

        if (state == 0) {
            memo[state][i] = max(dp(prices, memo, 0, i+1), dp(prices, memo, 1, i+1) - prices[i]);
        } else {
            memo[state][i] = max(dp(prices, memo, 1, i+1), dp(prices, memo, 0, i+2) + prices[i]);
        }

        return memo[state][i];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> memo(2, vector<int>(n, -1));

        memo[0][n-1] = 0;
        memo[1][n-1] = prices[n-1];

        return dp(prices, memo, 0, 0);
    }
};

//2 states: free (no neetcoin), hold (holding neetcoin, next action is to sell)

//a_i: best return if state is free on day i
//b_i: best return if state is hold on day i

//a_i = max(a_i+1, b_i+1 - prices[i])
//b_i = max(b_i+1, a_i+2 + prices[i])

//if buy at price p, then subtract p from total return
//if sell at price q, then add q to total return