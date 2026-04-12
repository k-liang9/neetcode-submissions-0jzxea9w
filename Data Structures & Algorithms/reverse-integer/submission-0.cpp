class Solution {
public:
    int reverse(int x) {
        int sign = 1;
        if (x < 0) {
            x = -x;
            sign = -1;
        }
        stack<int> s;
        while (x > 0) {
            int digit = x % 10;
            x /= 10;
            s.push(digit);
        }

        long res = 0;
        int mult = 1;
        while (!s.empty()) {
            int digit = s.top();
            s.pop();
            res += sign * digit * (long)mult;
            mult *= 10;
        }

        if ((sign == 1 && res > INT_MAX) || (sign == -1 && res < INT_MIN)) {
            return 0;
        }

        return res;
    }
};