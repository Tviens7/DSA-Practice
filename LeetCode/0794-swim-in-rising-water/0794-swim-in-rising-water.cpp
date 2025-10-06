class Solution {
public:
    int swimInWater(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        
        std::vector<std::vector<int>> dist(n, std::vector<int>(n, n * n));
        
        std::priority_queue<
            std::tuple<int, int, int>, 
            std::vector<std::tuple<int, int, int>>, 
            std::greater<std::tuple<int, int, int>>
        > pq;
        
        dist[0][0] = grid[0][0];
        pq.emplace(dist[0][0], 0, 0);
        
        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};
        
        while (!pq.empty()) {
            auto [t, r, c] = pq.top();
            pq.pop();
            
            if (r == n - 1 && c == n - 1) {
                return t;
            }
            
            if (t > dist[r][c]) {
                continue;
            }
            
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                    int new_t = std::max(t, grid[nr][nc]);
                    
                    if (new_t < dist[nr][nc]) {
                        dist[nr][nc] = new_t;
                        pq.emplace(new_t, nr, nc);
                    }
                }
            }
        }
        
        return dist[n - 1][n - 1];
    }
};