class Solution {
public:
    int dp(const string& text1, const string& text2, vector<vector<int>>& memo, int i, int j) {
        if (i >= text1.length() || j >= text2.length()) {
            return 0;
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        if (text1[i] == text2[j]) {
            memo[i][j] = 1 + dp(text1, text2, memo, i+1, j+1);
        } else {
            memo[i][j] = max(dp(text1, text2, memo, i+1, j), dp(text1, text2, memo, i, j+1));
        }

        return memo[i][j];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> memo(m, vector<int>(n, -1));

        return dp(text1, text2, memo, 0, 0);
    }
};