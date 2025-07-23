class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0)
            return 0;
        if (s.size() == 1)
            return 1;
        int max{0};
        for (int i = 0; i < s.size(); ++i) {
            std::set<char> hash;
            hash.insert(s[i]);
            int count = 1;
            for (int j = i + 1; j < s.size(); ++j) {
                if (hash.contains(s[j])) {
                    if (count > max) {
                        max = count;
                    }
                    break;
                }

                else{
                    ++count;
                    hash.insert(s[j]);
                }
                if (count > max)
                    max = count;
            }
        }
        return max;
    }
};