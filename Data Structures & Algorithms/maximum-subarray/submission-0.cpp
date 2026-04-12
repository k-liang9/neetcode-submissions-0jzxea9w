//create an array to store the maximum subarray ending at each index
//iterate over nums, max at index i = max(nums[i], nums[i] + max[i-1])
//iterate over max values array to find the maximum subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> tab(nums.size());
        tab[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            tab[i] = max(nums[i], nums[i] + tab[i-1]);
        }

        int max_subarr = tab[0];
        for (int cur : tab) {
            max_subarr = max(max_subarr, cur);
        }

        return max_subarr;
    }
};
