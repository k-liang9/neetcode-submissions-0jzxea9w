class Solution {
public:
    int get(vector<int>& vec, int i) {
        if (i < 0 || i >= vec.size()) {
            return 0;
        }

        return vec[i];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        string shortest;
        string longest;
        int len_shortest;
        int len_longest;
        if (m < n) {
            shortest = text1;
            longest = text2;
            len_shortest = m;
            len_longest = n;
        } else {
            shortest = text2;
            longest = text1;
            len_shortest = n;
            len_longest = m;
        }

        vector<int> vec1(len_shortest, 0);
        vector<int> vec2(len_shortest, 0);
        vector<int>& prev = vec1;
        vector<int>& cur = vec2;

        for (int i = len_longest-1; i >= 0; i--) {
            for (int j = len_shortest-1; j >= 0; j--) {
                if (longest[i] == shortest[j]) {
                    cur[j] = 1 + get(prev, j+1);
                } else {
                    cur[j] = max(get(prev, j), get(cur, j+1));
                }
            }
            swap(prev, cur);
        }

        return prev[0];
    }
};