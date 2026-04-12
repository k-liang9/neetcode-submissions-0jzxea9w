class Solution {
public:
    void dfs(
        const vector<int>& nums,
        int cnt,
        vector<vector<int>>& res,
        vector<bool>& used,
        vector<int>& cur
    ) {
        if (cnt >= nums.size()) {
            res.push_back(cur);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) {
                continue;
            }
            used[i] = true;
            cur.push_back(nums[i]);
            dfs(nums, cnt+1, res, used, cur);
            cur.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<bool> used(nums.size(), false);
        vector<int> cur;
        dfs(nums, 0, res, used, cur);

        return res;
    }
};
