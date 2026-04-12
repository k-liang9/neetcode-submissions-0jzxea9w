class Solution {
public:
    void dfs(
        const vector<int>& nums, 
        const unordered_map<int, int>& counts,
        int target, 
        int i, 
        int sum, 
        vector<vector<int>>& res, 
        vector<int>& cur,
        unordered_map<int, int>& cur_count) 
    {
        if (i >= nums.size()) {
            return;
        }

        for (int j = i; j < nums.size(); j++) {
            if (cur_count[nums[j]] >= counts.at(nums[j])) {
                continue;
            }

            int cur_sum = sum + nums[j];
            if (cur_sum < target) {
                cur.push_back(nums[j]);
                cur_count[nums[j]]++;
                dfs(nums, counts, target, j, cur_sum, res, cur, cur_count);
                cur_count[nums[j]]--;
                cur.pop_back();
            } else if (cur_sum == target) {
                cur.push_back(nums[j]);
                res.push_back(cur);
                cur.pop_back();
                return;
            } else {
                return;
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        unordered_map<int, int> counts;
        vector<int> distincts;
        for (int num : candidates) {
            counts[num]++;
        }

        for (auto& kv : counts) {
            distincts.push_back(kv.first);
        }

        sort(distincts.begin(), distincts.end());

        vector<vector<int>> res;
        vector<int> cur;
        unordered_map<int, int> cur_cnt;
        dfs(distincts, counts, target, 0, 0, res, cur, cur_cnt);
        return res;
    }
};
