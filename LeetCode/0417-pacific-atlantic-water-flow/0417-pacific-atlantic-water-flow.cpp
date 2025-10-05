class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) {
            return {};
        }

        int m = heights.size();
        int n = heights[0].size();
        
        std::vector<std::vector<bool>> pacific_reachable(m, std::vector<bool>(n, false));
        std::vector<std::vector<bool>> atlantic_reachable(m, std::vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            dfs(heights, pacific_reachable, i, 0, m, n);
            dfs(heights, atlantic_reachable, i, n - 1, m, n);
        }

        for (int j = 0; j < n; ++j) {
            dfs(heights, pacific_reachable, 0, j, m, n);
            dfs(heights, atlantic_reachable, m - 1, j, m, n);
        }

        std::vector<std::vector<int>> result;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific_reachable[i][j] && atlantic_reachable[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }

private:
    void dfs(std::vector<std::vector<int>>& heights, std::vector<std::vector<bool>>& visited, int r, int c, int m, int n) {
        if (visited[r][c]) {
            return;
        }
        visited[r][c] = true;

        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};

        for (int i = 0; i < 4; ++i) {
            int new_r = r + dr[i];
            int new_c = c + dc[i];

            if (new_r >= 0 && new_r < m && new_c >= 0 && new_c < n && heights[new_r][new_c] >= heights[r][c]) {
                dfs(heights, visited, new_r, new_c, m, n);
            }
        }
    }
};