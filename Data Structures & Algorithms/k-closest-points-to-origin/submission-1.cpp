class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comp = [](vector<int>& a, vector<int>& b) {
            long a_dist = a[0] * a[0] + a[1] * a[1];
            long b_dist = b[0] * b[0] + b[1] * b[1];
            return a_dist > b_dist;
        };
        
        make_heap(points.begin(), points.end(), comp);
        vector<vector<int>> ret;
        for (int i = 0; i < k; i++) {
            ret.push_back(points[0]);
            pop_heap(points.begin(), points.end(), comp);
            points.pop_back();
        }
        return ret;
    }
};
