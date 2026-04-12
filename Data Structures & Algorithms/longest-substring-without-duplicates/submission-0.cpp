class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t left = 0;
        size_t longest = 0;
        unordered_set<char> in_frame;
        for (size_t right = 0; right < s.length(); ++right) {
            char ch = s[right];
            if (in_frame.find(ch) != in_frame.end()) {
                while (s[left] != ch) {
                    in_frame.erase(s[left]);
                    left++;
                }
                left++;
            } else {
                in_frame.insert(ch);
                size_t length = right - left + 1;
                longest = max(length, longest);
            }
        }
        return longest;
    }
};
