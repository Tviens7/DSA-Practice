class Solution {
public:
    int numberOfPairs(std::vector<std::vector<int>>& points) {
        std::sort(points.begin(), points.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            if (a[0] != b[0]) {
                return a[0] < b[0];
            }
            return a[1] > b[1];
        });

        int count = 0;
        int n = points.size();

        for (int i = 0; i < n; ++i) {
            int y_A = points[i][1];

            int highest_y_blocker = -1e9 - 1;

            for (int j = i + 1; j < n; ++j) {
                int y_B = points[j][1];
                if (y_A >= y_B) {
                    if (y_B > highest_y_blocker) {
                        count++;
                    }
                    highest_y_blocker = std::max(highest_y_blocker, y_B);
                }
            }
        }
        return count;
    }
};