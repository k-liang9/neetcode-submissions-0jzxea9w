class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        int p_max = nums[0];
        int prev_p = 0;
        int prev_n = 0;
        for (int num : nums) {
            if (num >= 0) {
                prev_p = max(prev_p * num, num);
                prev_n = min(prev_n * num, num);
            } else {
                int temp = prev_p * num;
                prev_p = max(prev_n * num, num);
                prev_n = min(temp, num);
            }
            cout << prev_p << ' ' << prev_n << '\n';

            p_max = max(prev_p, p_max);
        }

        return p_max;
    }
};

//let p_i be the max positive product at i
//let n_i be the max negative product at i

//if nums[i] >= 0, then p_i = max(p_i-1 * nums[i], nums[i]), n_i = nums[i], n_i-1 * nums[i])
//if nums[i] < 0, then p_i = max(n_i-1 * nums[i], nums[i]), n_i = min(nums[i], p_i-1 * nums[i])

//at every iteration, take p_max = max(p_i, p_max)

//[-4, 1, -3, 1, -2, 10]

//-4: prev_p = max(n_i-1 * nums[i], nums[i]), prev_n = min(p_i-1*nums[i], nums[i])