#include <vector>

class Solution {
private:
    bool rows[9][10] = {false};
    bool cols[9][10] = {false};
    bool boxes[9][10] = {false};

public:
    void solveSudoku(std::vector<std::vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    int box_index = (i / 3) * 3 + (j / 3);
                    rows[i][num] = true;
                    cols[j][num] = true;
                    boxes[box_index][num] = true;
                }
            }
        }
        solve(board);
    }

private:
    bool solve(std::vector<std::vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    int box_index = (i / 3) * 3 + (j / 3);
                    
                    for (int num = 1; num <= 9; ++num) {
                        if (!rows[i][num] && !cols[j][num] && !boxes[box_index][num]) {
                            
                            board[i][j] = num + '0';
                            rows[i][num] = true;
                            cols[j][num] = true;
                            boxes[box_index][num] = true;

                            if (solve(board)) {
                                return true; 
                            }

                            board[i][j] = '.';
                            rows[i][num] = false;
                            cols[j][num] = false;
                            boxes[box_index][num] = false;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
};