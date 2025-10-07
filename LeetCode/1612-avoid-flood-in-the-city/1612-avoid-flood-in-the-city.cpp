class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n);
        unordered_map<int, int> full_lakes;
        set<int> dry_days;

        for (int i = 0; i < n; ++i) {
            int lake = rains[i];
            if (lake == 0) {
                dry_days.insert(i);
                ans[i] = 1;
            } else {
                ans[i] = -1;
                if (full_lakes.count(lake)) {
                    int last_rain_day = full_lakes[lake];
                    auto it = dry_days.upper_bound(last_rain_day);

                    if (it == dry_days.end()) {
                        return {};
                    }

                    int dry_day_to_use = *it;
                    ans[dry_day_to_use] = lake;
                    dry_days.erase(it);
                    full_lakes[lake] = i;
                } else {
                    full_lakes[lake] = i;
                }
            }
        }
        return ans;
    }
};