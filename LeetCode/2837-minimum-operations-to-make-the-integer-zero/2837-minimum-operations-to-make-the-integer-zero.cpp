class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {

        for (long long k = 1; k <= 61; ++k) {
            long long target = (long long)num1 - k * num2;

            if (k > target) {

                if (num2 >= 0) {
                    break;
                }

                continue;
            }

            if (__builtin_popcountll(target) <= k) {
                return k;
            }
        }

        return -1;
    }
};