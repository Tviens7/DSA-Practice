class Solution {
public:
    int trapRainWater(std::vector<std::vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) {
            return 0;
        }

        int m = heightMap.size();
        int n = heightMap[0].size();

        if (m <= 2 || n <= 2) {
            return 0;
        }

        using Cell = std::array<int, 3>;
        std::priority_queue<Cell, std::vector<Cell>, std::greater<Cell>> pq;
        std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    pq.push({heightMap[i][j], i, j});
                    visited[i][j] = true;
                }
            }
        }

        int total_water = 0;
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!pq.empty()) {
            Cell cell = pq.top();
            pq.pop();
            int h = cell[0];
            int r = cell[1];
            int c = cell[2];

            for (auto& dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    
                    total_water += std::max(0, h - heightMap[nr][nc]);
                    
                    pq.push({std::max(h, heightMap[nr][nc]), nr, nc});
                }
            }
        }

        return total_water;
    }
};