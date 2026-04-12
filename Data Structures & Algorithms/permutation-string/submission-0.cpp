class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }

        unordered_map<char, int> fcnt;
        unordered_map<char, int> s1cnt;
        int l = 0;

        for (char ch : s1) {
            s1cnt[ch]++;
        }

        for (int r = 0; r < s2.length(); r++) {
            fcnt[s2[r]]++;

            if (r < s1.length() - 1) {
                continue;
            }

            if (r >= s1.length()) {
                fcnt[s2[l]]--;
                l++;
            }

            bool is_perm = true;
            cout << "index " << r << '\n';
            for (auto& ch : s1cnt) {
                cout << ch.first << ", " << ch.second << '\n';
                if (fcnt[ch.first] != ch.second) {
                    is_perm = false;
                    break;
                }
            }
            if (is_perm) {
                return true;
            }
        }

        return false;
    }
};
