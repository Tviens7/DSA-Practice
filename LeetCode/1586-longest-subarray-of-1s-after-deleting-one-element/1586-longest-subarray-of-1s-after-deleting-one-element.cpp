class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0, right = 0, max = 0, zeros = 0;

        for (right; right < nums.size(); ++right) {
            if (nums[right] == 0)
                ++zeros;
            while (zeros > 1) {
                if (nums[left] == 0)
                    --zeros;
                ++left;
            }
            max = std::max(max, right - left);
        }
        return max;
    }
};