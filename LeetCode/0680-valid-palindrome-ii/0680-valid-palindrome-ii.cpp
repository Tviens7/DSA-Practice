class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            if (s[left] != s[right]) {
                int i1 = left + 1, j1 = right;
                while (i1 < j1 && s[i1] == s[j1]) {
                    i1++;
                    j1--;
                }

                int i2 = left, j2 = right - 1;
                while (i2 < j2 && s[i2] == s[j2]) {
                    i2++;
                    j2--;
                }

                return i1 >= j1 || i2 >= j2;
            }
            left++;
            right--;
        }

        return true;
    }
};