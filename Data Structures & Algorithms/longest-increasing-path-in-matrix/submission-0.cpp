class Solution {
public:
    vector<vector<int>> memo;

    bool in_range(int i, int j) {
        return i >= 0 && i < memo.size() && j >= 0 && j < memo[0].size();
    }

    int dp(const vector<vector<int>>& matrix, int i, int j) {
        if (!in_range(i, j)) {
            return 0;
        }

        if (memo[i][j] > 0) {
            return memo[i][j];
        }

        if (in_range(i+1, j) && matrix[i+1][j] > matrix[i][j]) {
            memo[i][j] = max(memo[i][j], dp(matrix, i+1, j));
        }

        if (in_range(i-1, j) && matrix[i-1][j] > matrix[i][j]) {
            memo[i][j] = max(memo[i][j], dp(matrix, i-1, j));
        }

        if (in_range(i, j+1) && matrix[i][j+1] > matrix[i][j]) {
            memo[i][j] = max(memo[i][j], dp(matrix, i, j+1));
        }

        if (in_range(i, j-1) && matrix[i][j-1] > matrix[i][j]) {
            memo[i][j] = max(memo[i][j], dp(matrix, i, j-1));
        }

        memo[i][j]++;

        return memo[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        memo.resize(m, vector<int>(n));

        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res = max(res, dp(matrix, i, j));
            }
        }

        return res;
    }
};

//let k_ij = longest path starting from i, j
//k_ij = max(k_(i+1)(j), k_(i-1)(j), k_(i)(j+1), k_(i)(j-1)) if they are greater than matrix[i][j]