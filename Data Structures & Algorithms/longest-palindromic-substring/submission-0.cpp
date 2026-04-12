class Solution {
public:
    string longestPalindrome(string s) {
        int res_len = 0;
        int res_start = 0;  // Store start position instead of center

        for (int i = 0; i < s.length(); i++) {
            // Odd-length palindromes (center at i)
            int l = i, r = i;
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                int cur_len = r - l + 1;
                if (cur_len > res_len) {
                    res_len = cur_len;
                    res_start = l;  // Store actual start position
                }
                l--;
                r++;
            }
            
            // Even-length palindromes (center between i and i+1)
            l = i;
            r = i + 1;
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                int cur_len = r - l + 1;
                if (cur_len > res_len) {
                    res_len = cur_len;
                    res_start = l;
                }
                l--;
                r++;
            }
        }

        return s.substr(res_start, res_len);
    }
};