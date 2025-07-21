class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash_groups;
        for (const std::string str : strs){
            string sort_str = str;
            sort(sort_str.begin(), sort_str.end());
            hash_groups[sort_str].push_back(str);
        }

        vector<vector<string>> result;
        for (const auto& [hash,val] : hash_groups){
            result.push_back(val);
        }
        return result;
    }
};