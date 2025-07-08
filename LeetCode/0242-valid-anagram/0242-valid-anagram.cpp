class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        map<char, int> sMap, tMap;
        for (int i = 0; i < s.size(); ++i){
            sMap[s[i]]++;
            tMap[t[i]]++;
        }
        return sMap == tMap;
    }
};