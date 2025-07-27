class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counters;
        for (int num : nums){
            counters[num]++;
        }

        auto it = std::max_element(counters.begin(), counters.end(),
    [](const auto& a, const auto& b) { return a.second < b.second; });

        return it->first;
    }
};