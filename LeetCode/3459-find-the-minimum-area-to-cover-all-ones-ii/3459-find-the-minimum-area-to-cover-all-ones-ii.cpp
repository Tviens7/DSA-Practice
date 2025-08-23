class Solution {
private:
    long long getMinArea(const std::vector<std::pair<int, int>>& ones, int r1, int c1, int r2, int c2) {
        int min_r = INT_MAX, max_r = INT_MIN;
        int min_c = INT_MAX, max_c = INT_MIN;
        bool has_one = false;

        for (const auto& p : ones) {
            int r = p.first;
            int c = p.second;
            if (r >= r1 && r <= r2 && c >= c1 && c <= c2) {
                has_one = true;
                min_r = std::min(min_r, r);
                max_r = std::max(max_r, r);
                min_c = std::min(min_c, c);
                max_c = std::max(max_c, c);
            }
        }

        if (!has_one) {
            return 0;
        }

        return (long long)(max_r - min_r + 1) * (max_c - min_c + 1);
    }

public:
    int minimumSum(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        std::vector<std::pair<int, int>> ones;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ones.push_back({i, j});
                }
            }
        }

        long long min_total_area = LLONG_MAX;

        for (int j1 = 0; j1 < n - 1; ++j1) {
            for (int j2 = j1 + 1; j2 < n - 1; ++j2) {
                long long a1 = getMinArea(ones, 0, 0, m - 1, j1);
                long long a2 = getMinArea(ones, 0, j1 + 1, m - 1, j2);
                long long a3 = getMinArea(ones, 0, j2 + 1, m - 1, n - 1);
                if (a1 > 0 && a2 > 0 && a3 > 0) {
                    min_total_area = std::min(min_total_area, a1 + a2 + a3);
                }
            }
        }

        for (int i1 = 0; i1 < m - 1; ++i1) {
            for (int i2 = i1 + 1; i2 < m - 1; ++i2) {
                long long a1 = getMinArea(ones, 0, 0, i1, n - 1);
                long long a2 = getMinArea(ones, i1 + 1, 0, i2, n - 1);
                long long a3 = getMinArea(ones, i2 + 1, 0, m - 1, n - 1);
                if (a1 > 0 && a2 > 0 && a3 > 0) {
                    min_total_area = std::min(min_total_area, a1 + a2 + a3);
                }
            }
        }

        for (int j = 0; j < n - 1; ++j) {
            for (int i = 0; i < m - 1; ++i) {
                long long a1, a2, a3;
                
                a1 = getMinArea(ones, 0, 0, i, j);
                a2 = getMinArea(ones, i + 1, 0, m - 1, j);
                a3 = getMinArea(ones, 0, j + 1, m - 1, n - 1);
                if (a1 > 0 && a2 > 0 && a3 > 0) {
                    min_total_area = std::min(min_total_area, a1 + a2 + a3);
                }
                
                a1 = getMinArea(ones, 0, 0, m - 1, j);
                a2 = getMinArea(ones, 0, j + 1, i, n - 1);
                a3 = getMinArea(ones, i + 1, j + 1, m - 1, n - 1);
                if (a1 > 0 && a2 > 0 && a3 > 0) {
                    min_total_area = std::min(min_total_area, a1 + a2 + a3);
                }
            }
        }
        
        for (int i = 0; i < m - 1; ++i) {
            for (int j = 0; j < n - 1; ++j) {
                long long a1, a2, a3;
                
                a1 = getMinArea(ones, 0, 0, i, j);
                a2 = getMinArea(ones, 0, j + 1, i, n - 1);
                a3 = getMinArea(ones, i + 1, 0, m - 1, n - 1);
                if (a1 > 0 && a2 > 0 && a3 > 0) {
                    min_total_area = std::min(min_total_area, a1 + a2 + a3);
                }

                a1 = getMinArea(ones, 0, 0, i, n - 1);
                a2 = getMinArea(ones, i + 1, 0, m - 1, j);
                a3 = getMinArea(ones, i + 1, j + 1, m - 1, n - 1);
                if (a1 > 0 && a2 > 0 && a3 > 0) {
                    min_total_area = std::min(min_total_area, a1 + a2 + a3);
                }
            }
        }

        return (int)min_total_area;
    }
};