class Solution {
public:
    bool checkValidString(string s) {
        stack<int> left, star;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                left.push(i);
            } else if (s[i] == '*') {
                star.push(i);
            } else {
                if (left.empty() && star.empty()) return false;
                if (!left.empty()) {
                    left.pop();
                } else {
                    star.pop();
                }
            }
        }

        while (!left.empty() && !star.empty()) {
            if (left.top() > star.top()) return false;
            left.pop();
            star.pop();
        }
        return left.empty();
    }
};

/*
keep track of:
- # open brackets
- # of * used as open brackets
- # of * used as closing brackets

at any point:
- if open = 0, and cur = *, then use * as open bracket
- if open > 0, and cur = *, then use * as closing bracket
- if open < 0, decrease the number of * used as closing bracket
    - if none were used, then return false

at the end:
- if excess of open brackets, decrease, the number of * used as open brackets
    - of no stars were used as opening brackets, and there is still excess, then return false
*/