class Solution {
public:
    //create memo array
    vector<int> memo;
    
    int dfs(int cur) {
        if (cur >= memo.size()) {
            return 0;
        }

        if (memo[cur] != 0) {
            return memo[cur];
        }

        memo[cur] = dfs(cur+1) + dfs(cur+2);
        return memo[cur];
    }

    int climbStairs(int n) {
        //memoization
        memo.resize(n+1);
        memo[n] = 1;

        //dfs on step 0, climb 1 or 2 step at every iteration
        return dfs(0);
    }
};
