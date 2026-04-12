class Solution {
public:
    bool canPartition(vector<int>& nums) {

        //find target value
        int target = 0;
        for (int num : nums) {
            target += num;
        }
        if (target % 2 != 0) {
            return false;
        }
        target /= 2;
        
        bool res = false;
        unordered_set<int> dp;
        for (int num : nums) {
            for (int i : dp) {
                cout << i << ' ';
                dp.insert(num + i);
            }
            dp.insert(num);
            cout << '\n';

            if (find(dp.begin(), dp.end(), target) != dp.end()) {
                res = true;
            }
        }

        return res;
    }
};
