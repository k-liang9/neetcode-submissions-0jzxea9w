class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }

        int pos = 0, jumps = 0;

        while (pos + nums[pos] < nums.size()-1) {
            int argmax_pos = pos;
            int max_range = pos;
            for (int i = pos+1; i <= pos + nums[pos]; i++) {
                int range = i + nums[i];
                if (max_range < range) {
                    argmax_pos = i;
                    max_range = range;
                }
            }
            jumps++;
            pos = argmax_pos;
        }

        return jumps + 1;
    }
};
