class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //create memo array
        vector<int> memo(nums.size(), 0);
        int res = 0;

        for (int i = nums.size()-1; i >= 0; i--) {
            int cur_max = 0;
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[j] > nums[i]) {
                    cur_max = max(cur_max, memo[j]);
                }
            }
            //if no numbers larger than nums[i] that follow, longest subsequence starting from i is 1
            memo[i] = cur_max + 1;
            res = max(res, memo[i]);
        }

        for (int i : memo) {
            cout << i << ' ';
        }

        //outer loop: iterate from nums.size()-1
        //inner loop: iterate from i+1, find the first number greater than the current, and add 1 to memo[j]
        //if greater than max, replace

        return res;
    }
};
