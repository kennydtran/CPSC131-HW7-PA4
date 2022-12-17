class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        // init
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        cost[m - 1][n - 1] = 0; visit[m - 1][n - 1] = true; q.push({m - 1, n - 1});
        // bfs
        while (!q.empty()) {
            int t = q.size();
            while (t--) {
                auto cur = q.front(); q.pop();
                int i = cur.first, j = cur.second, c = cost[i][j];
                // move from left: grid[i][j - 1]
                if (j - 1 >= 0) {
                    int pre = cost[i][j - 1];
                    cost[i][j - 1] = min(cost[i][j - 1], c + (grid[i][j - 1] != 1));
                    if (!visit[i][j - 1] || pre != cost[i][j - 1]) {
                        visit[i][j - 1] = true;
                        q.push({i, j - 1});
                    }
                }
                // move from right: grid[i][j + 1]
                if (j + 1 < n) {
                    int pre = cost[i][j + 1];
                    cost[i][j + 1] = min(cost[i][j + 1], c + (grid[i][j + 1] != 2));
                    if (!visit[i][j + 1] || pre != cost[i][j + 1]) {
                        visit[i][j + 1] = true;
                        q.push({i, j + 1});
                    }
                }
                // move from top grid[i - 1][j]
                if (i - 1 >= 0) {
                    int pre = cost[i - 1][j];
                    cost[i - 1][j] = min(cost[i - 1][j], c + (grid[i - 1][j] != 3));
                    if (!visit[i - 1][j] || pre != cost[i - 1][j]) {
                        visit[i - 1][j] = true;
                        q.push({i - 1, j});
                    }
                }
                // move from bottom grid[i + 1][j]
                if (i + 1 < m) {
                    int pre = cost[i + 1][j];
                    cost[i + 1][j] = min(cost[i + 1][j], c + (grid[i + 1][j] != 4));
                    if (!visit[i + 1][j] || pre != cost[i + 1][j]) {
                        visit[i + 1][j] = true;
                        q.push({i + 1, j});
                    }
                }
            }
        }
        return cost[0][0];
    }
};
