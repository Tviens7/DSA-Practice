class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minX = -1;
        int minY = -1;
        int maxX = -1;
        int maxY = -1;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1 && minX == -1) {
                    minX = j;
                    maxX = j;
                    minY = i;
                    maxY = i;
                }
                if (grid[i][j] == 1) {
                    if (minY > i)
                        minY = i;
                    if (maxY < i)
                        maxY = i;
                    if (minX > j)
                        minX = j;
                    if (maxX < j)
                        maxX = j; 
                }
            }
        }
        return (maxX - minX + 1) * (maxY - minY + 1);
    }
};