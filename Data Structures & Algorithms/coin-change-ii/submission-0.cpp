class Solution {
public:
    vector<vector<int>> memo;

    int dp(vector<int>& coins, int amt, int i) {
        if (i >= memo[0].size() || amt < 0) {
            return 0;
        }

        if (memo[amt][i] == -1) {
            memo[amt][i] = dp(coins, amt-coins[i], i) + dp(coins, amt, i+1);
        }

        return memo[amt][i];
    }

    int change(int amount, vector<int>& coins) {
        int num_coins = coins.size();
        memo.resize(amount+1);
        memo[0].resize(num_coins, 1);
        for (int i = 1; i <= amount; i++) {
            memo[i].resize(num_coins, -1);
        }

        return dp(coins, amount, 0);
    }
};

//k_i = distinct number of combinations that total to amount
//for every denomination of value d_j, k_i = k_(i-d_j) for all d_j
//but we run into overlap issues, for example

// coins = [1, 2, 3]
// amount = 3

// to make 3: we can have 1 + 2 and 2 + 1, both of which are counted. In reality, these are 1 such combination

// try adding the coins in order. once you start adding a higher denomination, you can no longer add a lower denomination
//2d dp: O(n*t), n = number of denominations, t = amount
//k_ab = number of combinations possible to sum to a using ONLY coins[b:]
//k_ab = k_(a-b)(b) + k_(a)(b+1)
//1. use 1 more of the current denomination, OR stop using the current denomination and start using the next denomination