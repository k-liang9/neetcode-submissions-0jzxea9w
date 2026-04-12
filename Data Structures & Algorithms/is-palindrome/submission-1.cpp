class Solution {
public:
    bool isPalindrome(string s) {
        int left_idx = 0;
        int right_idx = s.length() - 1;

        while (left_idx < right_idx) {
            char left = s[left_idx];
            char right = s[right_idx];
            if (!isalnum(left)) {
                left_idx++;
                continue;
            }
            if (!isalnum(right)) {
                right_idx--;
                continue;
            }
            if (isupper(left)) {
                left += ('a' - 'A');
            }
            if (isupper(right)) {
                right += ('a' - 'A');
            }
            if (left != right) {
                return false;
            }
            left_idx++;
            right_idx--;
        }
        return true;
    }
};
