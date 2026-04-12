class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        unordered_set<int> visited;

        int count = 0;
        queue<int> q;
        q.push(amount);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int amt = q.front();
                q.pop();

                if (amt == 0) {
                    return count;
                }

                if (find(visited.begin(), visited.end(), amt) != visited.end()) {
                    continue;
                }
                visited.insert(amt);

                for (int coin : coins) {
                    int new_amt = amt - coin;
                    if (new_amt >= 0) {
                        q.push(new_amt);
                    }
                }
            }
            count++;
        }

        return -1;
    }
};

//memoize whether you have previously visited a value before