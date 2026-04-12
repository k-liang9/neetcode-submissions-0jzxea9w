class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        if (m < n) {
            return 0;
        }

        vector<vector<int>> memo(2, vector<int>(n+1));
        int prev = 0;
        int cur = 1;
        
        memo[prev][n] = 1;
        memo[cur][n] = 1;

        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                memo[cur][j] = memo[prev][j];
                if (s[i] == t[j]) {
                    memo[cur][j] += memo[prev][j+1];
                }
            }
            swap(prev, cur
            );
        }

        return memo[prev][0];
    }
};

//let k_ij = number of distinct subsequences you can generate from s[i:] and t[j:]
//2 operations: either skip the character at s or use it if it is a match
//k_ij +=
//  k_(i+1)(j)
//  k_(i+1)(j+1), if s[i] == t[j]
//  k_mn = 1


//caaat
//aaat, cat | aaat, at
//aat, cat  | aat, at | aat, t