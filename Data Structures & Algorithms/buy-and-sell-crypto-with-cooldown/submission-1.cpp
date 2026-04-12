class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int free_tmr = 0;
        int free_tmrtmr = 0;
        int hold_tmr = prices[n-1];

        for (int i = n-2; i >= 0; i--) {
            int free_tdy = max(free_tmr, hold_tmr - prices[i]);
            int hold_tdy = max(hold_tmr, free_tmrtmr + prices[i]);

            free_tmrtmr = free_tmr;
            free_tmr = free_tdy;
            hold_tmr = hold_tdy;
        }

        return free_tmr;
    }
};

//top-down: O(n) time & space
//bottom-up optimal: O(n) time, O(1) space

//2 states: free (no neetcoin), hold (holding neetcoin, next action is to sell)

//a_i: best return if state is free on day i
//b_i: best return if state is hold on day i

//a_i = max(a_i+1, b_i+1 - prices[i])
//b_i = max(b_i+1, a_i+2 + prices[i])

//if buy at price p, then subtract p from total return
//if sell at price q, then add q to total return