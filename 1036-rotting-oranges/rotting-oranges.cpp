class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;

        // Step 1: Find all rotten & count fresh
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    fresh++;
            }
        }

        // If no fresh oranges
        if (fresh == 0) return 0;

        int minutes = 0;
        vector<pair<int,int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        // Step 2: BFS
        while (!q.empty()) {
            int size = q.size();
            bool rotted = false;

            for (int i = 0; i < size; i++) {
                auto [r, c] = q.front();
                q.pop();

                for (auto [dr, dc] : directions) {
                    int nr = r + dr;
                    int nc = c + dc;

                    // Check valid & fresh orange
                    if (nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                        fresh--;
                        rotted = true;
                    }
                }
            }

            // Only increment time if some orange rotted
            if (rotted) minutes++;
        }

        return (fresh == 0) ? minutes : -1;
    }
};