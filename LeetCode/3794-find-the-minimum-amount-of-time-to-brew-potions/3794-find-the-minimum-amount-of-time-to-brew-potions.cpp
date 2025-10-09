class Solution {
public:
    long long minTime(std::vector<int>& skill, std::vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();

        std::vector<long long> ps(n);
        ps[0] = skill[0];
        for (int i = 1; i < n; ++i) {
            ps[i] = ps[i - 1] + skill[i];
        }

        long long current_T = 0;

        for (int j = 1; j < m; ++j) {
            long long max_diff = (long long)ps[0] * mana[j - 1];

            for (int i = 1; i < n; ++i) {
                long long diff = (long long)ps[i] * mana[j - 1] - (long long)ps[i - 1] * mana[j];
                if (diff > max_diff) {
                    max_diff = diff;
                }
            }
            current_T += max_diff;
        }
        
        return current_T + (long long)ps[n - 1] * mana[m - 1];
    }
};