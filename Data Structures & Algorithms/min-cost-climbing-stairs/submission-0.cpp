class Solution {
public:
    int dfs(const vector<int>& cost, vector<int>& memo, int i) {
        if (memo[i] >= 0) {
            return memo[i];
        }

        int res = cost[i] + min(dfs(cost, memo, i+1), dfs(cost, memo, i+2));
        memo[i] = res;
        return res;
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> memo(n, -1);
        memo[n-1] = cost[n-1];
        memo[n-2] = cost[n-2];

        dfs(cost, memo, 0);

        return min(memo[0], memo[1]);
    }
};


// k_i = min cost to reach the end
// k_i = cost[i] + min(k_i+1, k_i+2)