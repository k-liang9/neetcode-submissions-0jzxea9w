class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp = {nums[0]};

        for (int num : nums) {
            if (num > dp[dp.size()-1]) {
                dp.push_back(num);
                continue;
            }

            int l = 0;
            int r = dp.size()-1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (dp[mid] >= num) {
                    if (mid == 0 || dp[mid-1] < num) {
                        dp[mid] = num;
                        break;
                    }
                    else {
                        r = mid-1;
                    }
                } else {
                    l = mid+1;
                }
            }
        }

        return dp.size();
    }
};
