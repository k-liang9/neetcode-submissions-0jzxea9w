class Solution {
public:

    bool isMatch(string s, string p) {
        vector<vector<bool> > memo(2, vector<bool>(s.length()+1, false));
        int prev = 0;
        int cur = 1;
        memo[prev][s.length()] = true;

        for (int i = p.length()-1; i >= 0; i--) {
            memo[cur][s.length()] = memo[prev][s.length()] & p[i] == '*';
            for (int j = s.length()-1; j >= 0; j--) {
                if (p[i] == '.') {
                    memo[cur][j] = memo[prev][j+1];
                } else if (p[i] != '*') {
                    if (p[i] == s[j]) {
                        memo[cur][j] = memo[prev][j+1];
                    } else {
                        memo[cur][j] = false;
                    }
                } else {
                    memo[cur][j] = memo[prev][j];
                    if (s[j] == p[i-1] || p[i-1] == '.') {
                        memo[cur][j] = memo[cur][j] | memo[cur][j+1];
                    }
                }
            }

            if (p[i] == '*') {
                i--;
            }

            for (int j = 0; j < s.length()+1; j++) {
                cout << memo[prev][j] << ' ';
            }
            cout << '\n';

            swap(prev, cur);
        }

        for (int j = 0; j < s.length()+1; j++) {
            cout << memo[prev][j] << ' ';
        }
        cout << '\n';

        return memo[prev][0];
    }
};


//let k_ij represent whether it is possible to match s[i:] and p[j:]

//if p[j] is char, then k_ij = false if s[i] != p[j], else k_(i+1)(j+1)

//if p[j] is ., k_ij = k_(i+1)(j+1)

//if p[j] is *, k_ij = k_(i+1)(j) | k_(i)(j+1)
// first condition if p[j-1] == s[i]