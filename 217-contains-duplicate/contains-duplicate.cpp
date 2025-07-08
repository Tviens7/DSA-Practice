class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> prev_seen;
        for (int num : nums){
            if (prev_seen.count(num))
                return true;
            else
                prev_seen.insert(num);
        }
        return false;
    }
};