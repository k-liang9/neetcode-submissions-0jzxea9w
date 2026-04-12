class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        auto comp = [](int a, int b) {
            return a > b;
        };
        priority_queue<int, vector<int>, decltype(comp)> pq(comp);
        for (int num : nums) {
            if (pq.size() < k) {
                pq.push(num);
            } else {
                if (num > pq.top()) {
                    pq.pop();
                    pq.push(num);
                }
            }
        }
        return pq.top();
    }
};
