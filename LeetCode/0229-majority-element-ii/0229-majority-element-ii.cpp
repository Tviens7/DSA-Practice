class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> numcount;
        vector<int> result;

        for (int num : nums){
            numcount[num]++;
        }

        for (auto pair : numcount){
            if (pair.second > nums.size()/3.0)
                result.push_back(pair.first);
        }
        
        return result;
    }
};