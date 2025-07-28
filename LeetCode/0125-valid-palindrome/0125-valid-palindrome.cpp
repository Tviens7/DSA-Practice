class Solution {
public:
    bool isPalindrome(string s) {
        string filtered;

        for (char letter : s){
            if (isalnum(letter))
                filtered.push_back(tolower(letter));
        }

        int left{0};
        int right = filtered.size() - 1;

        while (left < right){
            if (filtered[left] != filtered[right])
                return false;
            ++left;
            --right;
        }

        return true;
    }
};