class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> task_freq(26);
        for (char task : tasks) {
            task_freq[task - 'A']++;
        }
        sort(task_freq.begin(), task_freq.end());
        int maxf = task_freq[25];
        int idle = n*(maxf-1);
        for (int i = 24; i >= 0; i--) {
            idle -= min(maxf-1, task_freq[i]);
        }

        return tasks.size() + max(0, idle);
    }
};
