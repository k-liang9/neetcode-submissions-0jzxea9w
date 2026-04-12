class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int max = 0;
        while (left < right) {
            int cur_amt = (right - left) * min(heights[left], heights[right]);
            if (cur_amt > max) {
                max = cur_amt;
            }
            if (heights[left] < heights[right]) {
                left++;
            } else {
                right--;
            }
        }
        return max;
    }
};
