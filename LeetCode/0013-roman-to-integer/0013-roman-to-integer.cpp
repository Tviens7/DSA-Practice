class Solution {
public:
    int romanToInt(string s) {
        std::unordered_map<char, int> numerals = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int total{0};

        for (int i = 0; i < s.length(); ++i){
            int num_val = numerals[s[i]];

            if (i + 1 < s.length()){
                int next_val = numerals[s[i+1]];
                if (num_val >= next_val)
                    total += num_val;
                else
                    total -= num_val;
            }
            else
                total += num_val;
        }
        return total;
    }
};