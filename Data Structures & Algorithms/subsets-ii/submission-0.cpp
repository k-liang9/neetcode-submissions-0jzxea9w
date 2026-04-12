class Solution {
public:
    void dfs(const vector<int>& distincts, const unordered_map<int, int>& counts, int i, vector<vector<int>>& res, vector<int>& cur) {
        if (i >= distincts.size()) {
            res.push_back(cur);
            return;
        }

        int num = distincts[i];
        dfs(distincts, counts, i+1, res, cur);
        for (int cnt = 0; cnt < counts.at(num); cnt++) {
            cur.push_back(num);
            dfs(distincts, counts, i+1, res, cur);
        }
        for (int j = 0; j < counts.at(num); j++) {
            cur.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_map<int, int> counts;
        vector<int> distincts;
        for (int num : nums) {
            if (counts.find(num) == counts.end()) {
                distincts.push_back(num);
            }
            counts[num]++;
        }

        vector<vector<int>> res;
        vector<int> cur;
        dfs(distincts, counts, 0, res, cur);

        return res;
    }
};