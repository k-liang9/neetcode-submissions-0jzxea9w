class Solution {
public:
    vector<vector<int> > memo;

    int get(const vector<int>& nums, int i) {
        if (i < 0 || i >= nums.size()) {
            return 1;
        } else {
            return nums[i];
        }
    }

    int dp(const vector<int>& nums, int l, int r) {
        if (r < l) {
            return 0;
        }

        if (memo[l][r] != -1) {
            return memo[l][r];
        }

        for (int i = l; i <= r; i++) {
            memo[l][r] = max(
                memo[l][r],
                get(nums, l-1) * nums[i] * get(nums, r+1) + dp(nums, l, i-1) + dp(nums, i+1, r)
            );
        }

        return memo[l][r];
    }

    int maxCoins(vector<int>& nums) {
        memo.resize(nums.size(), vector<int>(nums.size(), -1));
        return dp(nums, 0, nums.size()-1);
    }
};


//let k_lr be the max sum achieved for a window of [l, r], assuming all numbers outside of l, r are unpopped
//assume l <= i <= r, and i is the last popped balloon of [l, r]. then k_lr = nums[l-1] * nums[i] * nums[r+1] + k_l(i-1) + k_(i+1)r