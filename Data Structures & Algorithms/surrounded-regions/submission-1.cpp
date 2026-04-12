class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
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
            if (in_range(i, j) && board[i][j] == 'O') {
                board[i][j] = 'T';
                q.push({i+1, j});
                q.push({i-1, j});
                q.push({i, j+1});
                q.push({i, j-1});
            }
            q.pop();
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'T') {
                    board[i][j] = 'O';
                } else {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
