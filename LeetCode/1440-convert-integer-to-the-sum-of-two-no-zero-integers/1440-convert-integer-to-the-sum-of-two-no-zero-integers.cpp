class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int x = 0;
        int y = 0;
        if (n%2 == 0) {
            x = n/2;
            y = n/2;
        }
        else {
            x = n/2+1;
            y = n/2;
        }

        bool xZero = true;
        bool yZero = true;

        while (xZero || yZero) {
            xZero = zeroChecker(x);
            yZero = zeroChecker(y);
            if (xZero || yZero) {
                ++x;
                --y;
            }
        }
        return {x, y};
    }

    bool zeroChecker(int num) {
        while (num > 0) {
            if (num % 10 == 0) {
                return true;
            }
            num /= 10;
        }
        return false;
    }
};