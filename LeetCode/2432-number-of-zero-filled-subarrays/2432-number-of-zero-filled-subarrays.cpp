class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long zCount = 0;
        long consec = 0;

        for (int num : nums) {
            if (num == 0) {
                ++consec;
            } else {
                zCount += (consec * (consec + 1)) / 2;
                consec = 0;
            }
        }
        zCount += (consec * (consec + 1)) / 2;
        return zCount;
    }
};