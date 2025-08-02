class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string new_str;

        for (int i = 0; i < word1.size() || i < word2.size(); ++i){
            if (i < word1.size())
                new_str += word1[i];
            if (i < word2.size())
                new_str += word2[i];
        }

        return new_str;
    }
};