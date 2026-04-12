class Solution {
public:
    int get(vector<int>& vec, int i) {
        if (i < 0 || i >= vec.size()) {
            return 0;
        }

        return vec[i];
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> memo(2, vector<int>(amount+1));
        int prev = 0;
        int cur = 1;
        memo[prev][0] = 1;

        sort(coins.begin(), coins.end());

        for (int i = 0; i < n; i++) {
            memo[cur][0] = 1;
            for (int j = 1; j <= amount; j++) {
                memo[cur][j] = get(memo[prev], j) + get(memo[cur], j - coins[i]);
            }
            swap(prev, cur);
        }

        return memo[prev][amount];
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