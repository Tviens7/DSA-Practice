class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        auto processDiagonal = [&](int start_row, int start_col) {
            vector<int> diagonal;
            int r = start_row;
            int c = start_col;
            
            while (r < n && c < n) {
                diagonal.push_back(grid[r][c]);
                r++;
                c++;
            }

            if (start_row - start_col >= 0) {
                sort(diagonal.rbegin(), diagonal.rend());
            } else {
                sort(diagonal.begin(), diagonal.end());
            }

            r = start_row;
            c = start_col;
            int index = 0;
            while (r < n && c < n) {
                grid[r][c] = diagonal[index];
                index++;
                r++;
                c++;
            }
        };

        for (int j = 0; j < n; ++j) {
            processDiagonal(0, j);
        }

        for (int i = 1; i < n; ++i) {
            processDiagonal(i, 0);
        }

        return grid;
    }
};