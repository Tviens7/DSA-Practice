class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int bestSum = nums[0];
        int currentSum = 0;

        for (int num : nums) {
            if (num > currentSum + num) {
                currentSum = num;
            } else {
                currentSum += num;
            }

            if (currentSum > bestSum) {
                bestSum = currentSum;
            }
        }
        return bestSum;
    }
};