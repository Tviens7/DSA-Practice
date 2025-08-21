class Solution {
public:
    int numSubmat(std::vector<std::vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) {
            return 0;
        }

        int m = mat.size();
        int n = mat[0].size();
        int totalCount = 0;
        std::vector<int> heights(n, 0);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1) {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }

            std::vector<int> dp(n, 0);
            std::stack<int> st;

            for (int j = 0; j < n; ++j) {
                while (!st.empty() && heights[st.top()] >= heights[j]) {
                    st.pop();
                }

                int prevSmallerIdx = st.empty() ? -1 : st.top();
                int width = j - prevSmallerIdx;
                
                dp[j] = heights[j] * width;

                if (!st.empty()) {
                    dp[j] += dp[prevSmallerIdx];
                }

                totalCount += dp[j];
                st.push(j);
            }
        }

        return totalCount;
    }
};