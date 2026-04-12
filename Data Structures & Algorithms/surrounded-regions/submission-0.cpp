class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            q.push({i, 0});
            q.push({i, n-1});
        }

        for (int i = 0; i < n; i++) {
            q.push({0, i});
            q.push({m-1, i});
        }

        auto in_range = [&](int i, int j) {
            return i >= 0 && j >= 0 && i < m && j < n;
        };

        while (!q.empty()) {
            pair<int, int>& cur = q.front();
            int i = cur.first;
            int j = cur.second;
            if (in_range(i, j)
            && !visited[i][j]
            && board[i][j] == 'O') {
                visited[i][j] = true;
                q.push({i+1, j});
                q.push({i-1, j});
                q.push({i, j+1});
                q.push({i, j-1});
            }
            q.pop();
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
