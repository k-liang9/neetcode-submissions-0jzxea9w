//strategy: jump to a position that gives you the largest range

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int pos = 0;
        while (pos + nums[pos] < nums.size()-1) {
            if (nums[pos] == 0) {
                return false;
            }
            int max_range = pos;
            int argmax_pos = pos;
            for (int i = pos+1; i <= pos + nums[pos]; i++) {
                if (max_range < i + nums[i]) {
                    argmax_pos = i;
                    max_range = i + nums[i];
                }
            }

            pos = argmax_pos;
        }

        return true;
    }
};
