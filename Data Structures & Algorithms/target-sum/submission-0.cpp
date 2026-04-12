class Solution {
public:
    int get(const vector<int>& vec, int i) {
        if (i < 0 || i >= vec.size()) {
            return 0;
        }

        return vec.at(i);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int max_sum = 0;
        for (int num : nums) {
            max_sum += num;
        }

        if (abs(target) > max_sum) {
            return 0;
        }

        vector<vector<int>> memo(2, vector<int>(2*max_sum + 1));
        int prev = 0;
        int cur = 1;
        memo[prev][0+max_sum] = 1;
    
        for (int i = nums.size()-1; i >= 0; i--) {
            for (int j = 0; j < memo[cur].size(); j++) {
                memo[cur][j] = get(memo[prev], j-nums[i]) + get(memo[prev], j+nums[i]);
            }
            swap(prev, cur);
        }

        return memo[prev][target + max_sum];
    }
};

//k_ij = number of ways to get to sum i starting from index j
//k_ij = k_(i-nums[j])(j+1) + k_(i+nums[j])(j+1)
