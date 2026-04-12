class Solution {
public:
    int characterReplacement(string s, int k) {
        char most_freq = s[0];
        unordered_map<char, int> counts;
        int left = 0;
        int right = 0;
        int max_size = 0;
        while (right < s.length()) {
            char cur = s[right];
            counts[cur]++;
            if (counts[cur] > counts[most_freq]) {
                most_freq = cur;
            }
            int cur_max_size = counts[most_freq] + k;

            int cur_size = right - left + 1;
            if (cur_size > cur_max_size) {
                counts[s[left]]--;
                left++;
                cur_size--;
            }

            max_size = max(cur_size, max_size);

            right++;
        }
        return max_size;
    }
};
