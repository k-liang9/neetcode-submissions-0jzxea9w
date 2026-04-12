class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        } else if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }

        int lastlast = nums[0];
        int last = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size()-1; i++) {
            int temp = max(last, nums[i] + lastlast);
            lastlast = last;
            last = temp;
        }

        int a = last;
        lastlast = nums[1];
        last = max(nums[1], nums[2]);

        for (int i = 3; i < nums.size(); i++) {
            int temp = max(last, nums[i] + lastlast);
            lastlast = last;
            last = temp;
        }

        int b = last;

        return max(a, b);
    }
};

//let a_i = max value that can be robbed from house i starting from house 1 & ending at house n-1
//let b_i = max value that can be robbed from house i starting from house 2 & ending at house n

//a_i = max(a_i-1, nums[i] + a_i-2)