#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stack{};
        vector<int> res{};
        res.resize(temperatures.size());
        for (int i = 0; i < temperatures.size(); ++i) {
            int cur_temp = temperatures[i];
            while (!stack.empty() && cur_temp > temperatures[stack.top()]) {
                int idx = stack.top();
                stack.pop();
                res[idx] = i - idx;
            }
            stack.push(i);
        }

        return res;
    }
};
