class Solution {
public:
    void recurse(const vector<int>& nums, vector<vector<int>>& ret, vector<int>& cur, int idx) {
        if (idx >= nums.size()) {
            return;
        }

        recurse(nums, ret, cur, idx+1);
        cur.push_back(nums[idx]);
        ret.push_back(cur);
        recurse(nums, ret, cur, idx+1);
        cur.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> cur;
        recurse(nums, ret, cur, 0);
        ret.push_back({});
        return ret;
    }
};
