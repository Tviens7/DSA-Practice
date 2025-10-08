class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> pairs;
        pairs.reserve(spells.size());
        
        for (int spell : spells) {
            long long min_strength = (success + spell - 1) / (long long)spell;
            auto it = lower_bound(potions.begin(), potions.end(), min_strength);
            pairs.push_back(potions.end() - it);
        }
        
        return pairs;
    }
};