class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> cons;
        unordered_map<char, int> vowels;

        for (char letter : s) {
            if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u') {
                ++vowels[letter];
            }
            else {
                ++cons[letter];
            }
        }

        int max_c = 0;
        int max_v = 0;

        for (const auto& pair : cons) {
            if (pair.second > max_c) {
                max_c = pair.second;
            }
        }
        for (const auto& pair : vowels) {
            if (pair.second > max_v) {
                max_v = pair.second;
            }
        }
        return max_c + max_v;
    }
};