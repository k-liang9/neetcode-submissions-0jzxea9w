class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int lastlast = nums[0];
        int last = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            int temp = max(last, nums[i] + lastlast);
            lastlast = last;
            last = temp;
        }

        return last;
    }
};

//let k_i = most value if ending at house i
//k_i = max(k_i-1, val_i + k_i-2)

//optimized dp: O(1) space: keep max value of houses i-1 and i-2