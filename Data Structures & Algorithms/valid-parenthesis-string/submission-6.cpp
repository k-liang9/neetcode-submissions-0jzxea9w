class Solution {
public:
    bool checkValidString(string s) {
        int min_open = 0, max_open = 0;

        for (char ch : s) {
            if (ch == '(') {
                min_open++;
                max_open++;
            } else if (ch == ')') {
                min_open--;
                max_open--;
            } else {
                min_open--;
                max_open++;
            }

            if (max_open < 0) {
                return false;
            }
            min_open = max(min_open, 0);
        }

        return min_open == 0;

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