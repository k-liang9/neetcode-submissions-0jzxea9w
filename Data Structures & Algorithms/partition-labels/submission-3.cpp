class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<pair<int, int>> ints;
        unordered_map<char, int> idx;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (idx.find(ch) != idx.end()) {
                ints[idx[ch]].second = i;
            } else {
                idx[ch] = ints.size();
                ints.push_back({i, i});
            }
        }

        vector<int> ret;
        pair<int, int> cur = ints[0];
        for (int i = 1; i < ints.size(); i++) {
            auto& interval = ints[i];
            cout << interval.first << ' ' << interval.second << '\n';
            if (interval.first < cur.second) {
                cur.second = max(cur.second, interval.second);
            } else {
                ret.push_back(cur.second - cur.first + 1);
                cur = interval;
            }
        }
        ret.push_back(cur.second - cur.first + 1);

        return ret;
    }
};