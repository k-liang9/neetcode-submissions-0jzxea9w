class Solution {
public:
    bool dp(const unordered_set<string>& dict, string& s, vector<int>& memo, int i) {
        if (i == s.length()) {
            return true;
        }

        if (memo[i] >= 0) {
            return memo[i];
        }

        for (int j = 0; i+j <= s.length(); j++) {
            string sstr = s.substr(i, j);
            cout << sstr << '\n';
            if (find(dict.begin(), dict.end(), sstr) != dict.end()) {
                if (dp(dict, s, memo, i+j)) {
                    memo[i] = 1;
                    return true;
                }
            }
        }

        memo[i] = 0;
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;

        for (string& word : wordDict) {
            dict.insert(word);
        }

        vector<int> memo(s.length(), -1);
        bool res = dp(dict, s, memo, 0);
        for (bool b : memo) {
            cout << b << ' ';
        }
        return res;
    }
};
