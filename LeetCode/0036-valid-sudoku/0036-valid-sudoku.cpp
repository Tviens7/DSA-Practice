class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        std::vector<std::unordered_set<char>> rows(9);
        std::vector<std::unordered_set<char>> cols(9);
        std::vector<std::unordered_set<char>> boxes(9);

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char num = board[i][j];

                if (num == '.') {
                    continue;
                }

                int box_index = (i / 3) * 3 + (j / 3);

                if (rows[i].count(num)) {
                    return false;
                }

                if (cols[j].count(num)) {
                    return false;
                }
                
                if (boxes[box_index].count(num)) {
                    return false;
                }
                
                rows[i].insert(num);
                cols[j].insert(num);
                boxes[box_index].insert(num);
            }
        }

        return true;
    }
};