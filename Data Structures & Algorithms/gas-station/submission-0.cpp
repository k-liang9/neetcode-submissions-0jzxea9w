/*
1. keep track of start position, cur position
2. iterate from start position, keep a running sum, add net gain of gas to running sum at every station
3. if running sum becomes negative, that means the start position is not feasible
4. start position = cur position, start checking from start position again
5. runtime: O(n)
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int cur = 0, start = 0, net_gas = 0;
        bool looped = false;
        while (true) {
            if (cur == gas.size()-1) {
                looped = true;
            }

            net_gas += gas[cur] - cost[cur];
            cur = (cur + 1) % gas.size();
            
            if (net_gas < 0) {
                if (looped) {
                    return -1;
                } else {
                    net_gas = 0;
                    start = cur;
                }
            } else {
                if (start == cur) {
                    return start;
                }
            }
        }
    }
};

//gas = [1, 2, 3, 4], cost = [2, 2, 4, 1]
//start = 3
//cur = 3
//net_gas = 1
//looped = true