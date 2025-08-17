class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 1)
            return true;
        while (n > 3 && n % 3 == 0)
            n /= 3;
        if (n == 3)
            return true;
        return false;
    }
};