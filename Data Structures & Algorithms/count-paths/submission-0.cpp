class Solution {
public:

    int dp(vector<vector<int>>& memo, int i, int j) {
        if (i < 0 || i >= memo.size() || j < 0 || j >= memo[0].size()) {
            return 0;
        }

        if (memo[i][j] != 0) {
            return memo[i][j];
        }

        memo[i][j] = dp(memo, i+1, j) + dp(memo, i, j+1);

        return memo[i][j];
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n, 0));
        
        memo[m-1][n-1] = 1;
        return dp(memo, 0, 0);
    }

};

//k_ij = # ways to get to m-1, n-1 from i, j