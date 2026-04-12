class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size()-2; i++) {
            if (i != 0 && nums[i] == nums[i-1]) {
                continue;
            }

            int left_ptr = i+1;
            int right_ptr = nums.size() - 1;
            int target = -nums[i];
            while (left_ptr < right_ptr) {
                int left_val = nums[left_ptr];
                int right_val = nums[right_ptr];
                if (left_val + right_val > target) {
                    while(nums[right_ptr] == right_val && right_ptr > 0) {
                        right_ptr--;
                    }
                } else if (left_val + right_val < target) {
                    while (nums[left_ptr] == left_val && left_ptr < nums.size()-1) {
                        left_ptr++;
                    }
                } else {
                    vector<int> triple = {nums[i], left_val, right_val};
                    res.push_back(triple);
                    while (nums[left_ptr] == left_val && left_ptr < nums.size()-1) {
                        left_ptr++;
                    }
                    while(nums[right_ptr] == right_val && right_ptr > 0) {
                        right_ptr--;
                    }
                }
            }
        }
        return res;
    }
};
