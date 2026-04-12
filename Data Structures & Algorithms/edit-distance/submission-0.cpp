class Solution {
public:
    int minDistance(string word1, string word2) {
        int min_len = min(word1.length(), word2.length());
        int max_len = max(word1.length(), word2.length());
        string min_str, max_str;
        if (min_len == word1.length()) {
            min_str = word1;
            max_str = word2;
        } else {
            min_str = word2;
            max_str = word1;
        }

        vector<vector<int>> memo(2, vector<int>(min_len+1));
        int prev = 0;
        int cur = 1;
        memo[prev][min_len] = 0;
        for (int i = 0; i <= min_len; i++) {
            memo[prev][i] = min_len - i;
        }

        for (int cur : memo[prev]) {
            cout << cur << ' ';
        }
        cout << '\n';

        for (int i = max_len - 1; i >= 0; i--) {
            memo[cur][min_len] = max_len - i;
            for (int j = min_len - 1; j >= 0; j--) {
                if (max_str[i] == min_str[j]) {
                    memo[cur][j] = memo[prev][j+1];
                } else {
                    memo[cur][j] = 1 + min(memo[prev][j], min(memo[cur][j+1], memo[prev][j+1]));
                }
            }
            swap(prev, cur);

            for (int cur : memo[prev]) {
                cout << cur << ' ';
            }
            cout << '\n';
        }

        return memo[prev][0];
    }
};

//let k_ij = least number of operations needed to transform word1[i:] into word2[j:]
//k_ij =
//  k_(i+1)(j+1), if word1[i] == word2[j]
//  1 + min(k_(i+1)(j), k_(i)(j+1), k_(i+1)(j+1))
//          delete      add         replace

//bottom up