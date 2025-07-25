class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> products(nums.size());

        int prefix{1};
        for (int i = 0; i < nums.size(); ++i){
            products[i] = prefix;
            prefix *= nums[i];
        }

        int suffix{1};
        for (int i = nums.size() - 1; i >= 0; --i){
            products[i] *= suffix;
            suffix *= nums[i];
        }

        return products;
    }
};