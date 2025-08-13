class Solution {
public:
    std::vector<int> sortArray(std::vector<int>& nums) {
        if (nums.empty()) {
            return nums;
        }

        int minVal = *std::min_element(nums.begin(), nums.end());
        int maxVal = *std::max_element(nums.begin(), nums.end());

        int range = maxVal - minVal + 1;
        std::vector<int> counts(range, 0);

        for (int num : nums) {
            counts[num - minVal]++;
        }

        int index = 0;
        for (int i = 0; i < range; ++i) {
            while (counts[i] > 0) {
                nums[index] = i + minVal;
                index++;
                counts[i]--;
            }
        }
        
        return nums;
    }
};