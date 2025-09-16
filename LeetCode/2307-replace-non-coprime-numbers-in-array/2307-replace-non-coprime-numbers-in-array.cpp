class Solution {
public:
    std::vector<int> replaceNonCoprimes(std::vector<int>& nums) {
        std::vector<int> res;
        
        for (int num : nums) {
            long long current = num;
            
            while (!res.empty()) {
                long long prev = res.back();
                long long common_divisor = std::gcd(prev, current);
                
                if (common_divisor == 1) {
                    break;
                }
                res.pop_back();

                current = (prev / common_divisor) * current;
            }

            res.push_back(static_cast<int>(current));
        }
        
        return res;
    }
};