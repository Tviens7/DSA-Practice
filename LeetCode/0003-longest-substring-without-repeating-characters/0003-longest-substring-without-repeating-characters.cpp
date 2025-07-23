class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::vector<int> index(128, 0);
        int max{0};
        int left{0};

        for(int right = 0; right < s.size(); ++right){
            char current = s[right];

            left = std::max(left, index[current]);

            index[current] = right + 1;

            max = std::max(max, right - left + 1);
        }
        return max;
    }
};