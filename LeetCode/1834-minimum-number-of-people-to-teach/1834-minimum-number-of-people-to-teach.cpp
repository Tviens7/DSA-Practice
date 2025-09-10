class Solution {
public:
    int minimumTeachings(int n, std::vector<std::vector<int>>& languages, std::vector<std::vector<int>>& friendships) {
        int m = languages.size();
        std::vector<std::unordered_set<int>> lang_sets(m);
        for (int i = 0; i < m; ++i) {
            for (int lang : languages[i]) {
                lang_sets[i].insert(lang);
            }
        }

        std::unordered_set<int> problem_users;
        for (const auto& friendship : friendships) {
            int u = friendship[0] - 1;
            int v = friendship[1] - 1;

            bool can_communicate = false;
            for (int lang : lang_sets[u]) {
                if (lang_sets[v].count(lang)) {
                    can_communicate = true;
                    break;
                }
            }

            if (!can_communicate) {
                problem_users.insert(u);
                problem_users.insert(v);
            }
        }

        if (problem_users.empty()) {
            return 0;
        }

        int min_teachings = m + 1;
        for (int l = 1; l <= n; ++l) {
            int current_teachings = 0;
            for (int user_idx : problem_users) {
                if (lang_sets[user_idx].count(l) == 0) {
                    current_teachings++;
                }
            }
            min_teachings = std::min(min_teachings, current_teachings);
        }

        return min_teachings;
    }
};