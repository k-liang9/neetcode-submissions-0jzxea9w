class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 1) {
            return s == "0" ? 0 : 1;
        }

        if (s[0] == '0') {
            return 0;
        }

        int lastlast = 1;
        int last = 0;
        int concat = (s[0]-'0') * 10 + (s[1]-'0');
        if (concat >= 10 && concat <= 26) {
            last++;
        }
        if (s[1] - '0' != 0) {
            last++;
        }

        for (int i = 2; i < s.length(); i++) {
            int temp = 0;
            concat = (s[i-1]-'0') * 10 + (s[i]-'0');
            if (concat >= 10 && concat <= 26) {
                temp += lastlast;
                cout << "lastlast";
            }
            if (s[i] != '0') {
                temp += last;
                cout << "last";
            }
            lastlast = last;
            last = temp;
        }

        return last;
    }
};

// work backwards:
// let k_i denote the number of possible configurations ending at index[i]
// k_i = s[i-1]s[i] and k_i-2 + s[i] and k_i-1, if any are possible