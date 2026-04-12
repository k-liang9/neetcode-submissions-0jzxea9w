class Solution {
public:

    bool isInterleave(string s1, string s2, string s3) {
        if (s3.length() != s1.length() + s2.length()) {
            return false;
        }

        string min_str, max_str;
        int min_len = min(s1.length(), s2.length());
        int max_len = max(s1.length(), s2.length());
        if (min_len == s1.length()) {
            min_str = s1;
            max_str = s2;
        } else {
            min_str = s2;
            max_str = s1;
        }

        vector<vector<bool>> memo(2, vector<bool>(min_len+1));
        int prev = 0;
        int cur = 1;

        //fill in first prev
        memo[prev][min_len] = true;
        for (int i = min_len-1; i >= 0; i--) {
            if (min_str[i] == s3[max_len + i]) {
                memo[prev][i] = true;
            } else {
                break;
            }
        }
        cout << "min: " << min_str << '\n';
        cout << "max: " << max_str << '\n';

        for (bool b : memo[prev]) {
            cout << b << ' ';
        }
        cout << '\n';

        //bottom up
        for (int i = max_len-1; i >= 0; i--) {
            if (max_str[i] == s3[min_len + i]) {
                memo[cur][min_len] = memo[prev][min_len];
            } else {
                memo[cur][min_len] = false;
            }
            for (int j = min_len-1; j >= 0; j--) {
                bool res = false;
                if (max_str[i] == s3[i+j]) {
                    res |= memo[prev][j];
                }
                if (min_str[j] == s3[i+j]) {
                    res |= memo[cur][j+1];
                }
                memo[cur][j] = res;
            }
            swap(prev, cur);

            for (bool b : memo[prev]) {
                cout << b << ' ';
            }
            cout << '\n';
        }

        return memo[prev][0];
    }
};

//let k_ij = true if the substring of s1[i:] and s2[j:] makes s3[i+j:]
//k_ij |= 
//  k_(i+1, j), if s1[i] == s3[i+j]
//  k_(i, j+1), if s1[j] == s3[i+j]
//k_ij = false otherwise

//k_mj = k_m(j+1) if s2[j] == s3[m+j]
//k_in = k_(i+1)n if s1[i] == s3[i+1]

//base condition: k_mn = true
//return: k_00

//bottom up: fill out memo[m][i], then use that as prev to fill out memo[m-1][i], all the way to memo[0]

//O(m*n) time
//O(min(m, n)) space