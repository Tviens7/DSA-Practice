using namespace std;

class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int max_len = 0;

        auto get_expected_val = [](int k) {
            if (k == 0) return 1;
            return (k % 2 == 1) ? 2 : 0;
        };
        
        vector<vector<vector<int>>> dp_s(4, vector<vector<int>>(n, vector<int>(m, 0)));
        vector<vector<vector<int>>> dp_v(4, vector<vector<int>>(n, vector<int>(m, 0)));

        // Pass 1: Straight Segments
        // Dir 0: TL -> BR
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                if (grid[r][c] == 1) {
                    dp_s[0][r][c] = 1;
                } else {
                    if (r > 0 && c > 0 && dp_s[0][r - 1][c - 1] > 0) {
                        int prev_len = dp_s[0][r - 1][c - 1];
                        if (grid[r][c] == get_expected_val(prev_len)) {
                            dp_s[0][r][c] = prev_len + 1;
                        }
                    }
                }
                max_len = max(max_len, dp_s[0][r][c]);
            }
        }
        // Dir 1: TR -> BL
        for (int r = 0; r < n; ++r) {
            for (int c = m - 1; c >= 0; --c) {
                if (grid[r][c] == 1) {
                    dp_s[1][r][c] = 1;
                } else {
                    if (r > 0 && c < m - 1 && dp_s[1][r - 1][c + 1] > 0) {
                        int prev_len = dp_s[1][r - 1][c + 1];
                        if (grid[r][c] == get_expected_val(prev_len)) {
                            dp_s[1][r][c] = prev_len + 1;
                        }
                    }
                }
                max_len = max(max_len, dp_s[1][r][c]);
            }
        }
        // Dir 2: BR -> TL
        for (int r = n - 1; r >= 0; --r) {
            for (int c = m - 1; c >= 0; --c) {
                if (grid[r][c] == 1) {
                    dp_s[2][r][c] = 1;
                } else {
                    if (r < n - 1 && c < m - 1 && dp_s[2][r + 1][c + 1] > 0) {
                        int prev_len = dp_s[2][r + 1][c + 1];
                        if (grid[r][c] == get_expected_val(prev_len)) {
                            dp_s[2][r][c] = prev_len + 1;
                        }
                    }
                }
                max_len = max(max_len, dp_s[2][r][c]);
            }
        }
        // Dir 3: BL -> TR
        for (int r = n - 1; r >= 0; --r) {
            for (int c = 0; c < m; ++c) {
                if (grid[r][c] == 1) {
                    dp_s[3][r][c] = 1;
                } else {
                    if (r < n - 1 && c > 0 && dp_s[3][r + 1][c - 1] > 0) {
                        int prev_len = dp_s[3][r + 1][c - 1];
                        if (grid[r][c] == get_expected_val(prev_len)) {
                            // This line is now corrected
                            dp_s[3][r][c] = prev_len + 1;
                        }
                    }
                }
                max_len = max(max_len, dp_s[3][r][c]);
            }
        }
        
        // Pass 2: V-Shaped Segments (This part was already correct)
        // Dir 0 (from 3)
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                if (r > 0 && c > 0) {
                    if (dp_v[0][r - 1][c - 1] > 0) {
                        int prev_len = dp_v[0][r - 1][c - 1];
                        if (grid[r][c] == get_expected_val(prev_len)) {
                            dp_v[0][r][c] = prev_len + 1;
                        }
                    }
                    if (dp_s[3][r - 1][c - 1] > 0) {
                        int prev_len = dp_s[3][r - 1][c - 1];
                        if (grid[r][c] == get_expected_val(prev_len)) {
                            dp_v[0][r][c] = max(dp_v[0][r][c], prev_len + 1);
                        }
                    }
                }
                max_len = max(max_len, dp_v[0][r][c]);
            }
        }
        // Dir 1 (from 0)
        for (int r = 0; r < n; ++r) {
            for (int c = m - 1; c >= 0; --c) {
                if (r > 0 && c < m - 1) {
                    if (dp_v[1][r - 1][c + 1] > 0) {
                        int prev_len = dp_v[1][r - 1][c + 1];
                        if (grid[r][c] == get_expected_val(prev_len)) {
                            dp_v[1][r][c] = prev_len + 1;
                        }
                    }
                    if (dp_s[0][r - 1][c + 1] > 0) {
                        int prev_len = dp_s[0][r - 1][c + 1];
                        if (grid[r][c] == get_expected_val(prev_len)) {
                            dp_v[1][r][c] = max(dp_v[1][r][c], prev_len + 1);
                        }
                    }
                }
                max_len = max(max_len, dp_v[1][r][c]);
            }
        }
        // Dir 2 (from 1)
        for (int r = n - 1; r >= 0; --r) {
            for (int c = m - 1; c >= 0; --c) {
                if (r < n - 1 && c < m - 1) {
                    if (dp_v[2][r + 1][c + 1] > 0) {
                        int prev_len = dp_v[2][r + 1][c + 1];
                        if (grid[r][c] == get_expected_val(prev_len)) {
                            dp_v[2][r][c] = prev_len + 1;
                        }
                    }
                    if (dp_s[1][r + 1][c + 1] > 0) {
                        int prev_len = dp_s[1][r + 1][c + 1];
                        if (grid[r][c] == get_expected_val(prev_len)) {
                            dp_v[2][r][c] = max(dp_v[2][r][c], prev_len + 1);
                        }
                    }
                }
                max_len = max(max_len, dp_v[2][r][c]);
            }
        }
        // Dir 3 (from 2)
        for (int r = n - 1; r >= 0; --r) {
            for (int c = 0; c < m; ++c) {
                if (r < n - 1 && c > 0) {
                   if (dp_v[3][r + 1][c - 1] > 0) {
                        int prev_len = dp_v[3][r + 1][c - 1];
                        if (grid[r][c] == get_expected_val(prev_len)) {
                            dp_v[3][r][c] = prev_len + 1;
                        }
                    }
                    if (dp_s[2][r + 1][c - 1] > 0) {
                        int prev_len = dp_s[2][r + 1][c - 1];
                        if (grid[r][c] == get_expected_val(prev_len)) {
                            dp_v[3][r][c] = max(dp_v[3][r][c], prev_len + 1);
                        }
                    }
                }
                max_len = max(max_len, dp_v[3][r][c]);
            }
        }

        return max_len;
    }
};