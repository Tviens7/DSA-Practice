class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int, int> counts;
        for (int p : power) {
            counts[p]++;
        }

        vector<int> unique_powers;
        unique_powers.reserve(counts.size());
        for (auto const& [p, count] : counts) {
            unique_powers.push_back(p);
        }
        
        int n = unique_powers.size();
        if (n == 0) {
            return 0;
        }

        vector<long long> dp(n, 0);
        dp[0] = static_cast<long long>(unique_powers[0]) * counts[unique_powers[0]];

        int j = -1;
        for (int i = 1; i < n; ++i) {
            int current_power_val = unique_powers[i];
            
            while (j + 1 < i && unique_powers[j + 1] < current_power_val - 2) {
                j++;
            }
            
            long long damage_if_cast = static_cast<long long>(current_power_val) * counts[current_power_val];
            if (j >= 0) {
                damage_if_cast += dp[j];
            }

            long long damage_if_not_cast = dp[i - 1];
            
            dp[i] = max(damage_if_cast, damage_if_not_cast);
        }

        return dp[n - 1];
    }
};