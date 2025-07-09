class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;

        for (int i = 0; i < nums.size(); ++i){
            int diff = target - nums[i];
            if (hashmap.find(diff) != hashmap.end())
                return {i, hashmap[diff]};
            hashmap[nums[i]] = i;
        }
        return {0, 0};
    }
};