class Spreadsheet {
private:
    std::vector<std::vector<int>> grid;

    std::pair<int, int> parseCell(const std::string& cell) {
        int col = cell[0] - 'A';
        int row = std::stoi(cell.substr(1)) - 1;
        return {row, col};
    }

    int getTermValue(const std::string& term) {
        if (std::isalpha(term[0])) {
            std::pair<int, int> coords = parseCell(term);
            return grid[coords.first][coords.second];
        } else {
            return std::stoi(term);
        }
    }

public:
    Spreadsheet(int rows) {
        grid.assign(rows, std::vector<int>(26, 0));
    }

    void setCell(std::string cell, int value) {
        std::pair<int, int> coords = parseCell(cell);
        grid[coords.first][coords.second] = value;
    }

    void resetCell(std::string cell) {
        setCell(cell, 0);
    }

    int getValue(std::string formula) {
        size_t plus_pos = formula.find('+');
        std::string term1_str = formula.substr(1, plus_pos - 1);
        std::string term2_str = formula.substr(plus_pos + 1);
        return getTermValue(term1_str) + getTermValue(term2_str);
    }
};