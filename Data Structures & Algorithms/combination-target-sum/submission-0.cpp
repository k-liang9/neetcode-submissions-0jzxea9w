class Solution {
public:
    void dfs(const vector<int>& nums, int target, int i, int sum, vector<vector<int>>& res, vector<int>& cur) {
        if (i >= nums.size()) {
            return;
        }

        for (int num : cur) {
            cout << num << ' ';
        }
        cout << '\n';

        for (int j = i; j < nums.size(); j++) {
            int new_sum = sum + nums[j];
            if (new_sum < target) {
                cur.push_back(nums[j]);
                dfs(nums, target, j, new_sum, res, cur);
                cur.pop_back();
            } else if (new_sum == target) {
                cur.push_back(nums[j]);
                res.push_back(cur);
                cur.pop_back();
                return;
            } else {
                return;
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        sort(nums.begin(), nums.end());
        dfs(nums, target, 0, 0, res, cur);
        return res;
    }
};
