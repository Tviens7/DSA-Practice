class Solution {
public:
    bool judgePoint24(std::vector<int>& cards) {
        std::vector<double> nums(cards.begin(), cards.end());
        return solve(nums);
    }

private:
    bool solve(std::vector<double>& nums) {
        if (nums.size() == 1) {
            return std::abs(nums[0] - 24.0) < 1e-6;
        }

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                std::vector<double> next_nums;
                for (int k = 0; k < nums.size(); ++k) {
                    if (k != i && k != j) {
                        next_nums.push_back(nums[k]);
                    }
                }

                double a = nums[i];
                double b = nums[j];

                std::vector<double> results;
                results.push_back(a + b);
                results.push_back(a - b);
                results.push_back(b - a);
                results.push_back(a * b);
                if (b != 0) results.push_back(a / b);
                if (a != 0) results.push_back(b / a);

                for (double res : results) {
                    next_nums.push_back(res);
                    if (solve(next_nums)) {
                        return true;
                    }
                    next_nums.pop_back();
                }
            }
        }

        return false;
    }
};