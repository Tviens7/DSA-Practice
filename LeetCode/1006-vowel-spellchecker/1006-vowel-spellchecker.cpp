class Solution {
public:
    std::vector<std::string> spellchecker(std::vector<std::string>& wordlist, std::vector<std::string>& queries) {
        std::unordered_set<std::string> words_perfect;
        std::unordered_map<std::string, std::string> words_case;
        std::unordered_map<std::string, std::string> words_vowel;

        for (const std::string& word : wordlist) {
            words_perfect.insert(word);

            std::string lower_word = toLower(word);
            if (words_case.find(lower_word) == words_case.end()) {
                words_case[lower_word] = word;
            }

            std::string devoweled_word = devowel(word);
            if (words_vowel.find(devoweled_word) == words_vowel.end()) {
                words_vowel[devoweled_word] = word;
            }
        }

        std::vector<std::string> result;
        result.reserve(queries.size());

        for (const std::string& query : queries) {
            if (words_perfect.count(query)) {
                result.push_back(query);
                continue;
            }

            std::string lower_query = toLower(query);
            if (words_case.count(lower_query)) {
                result.push_back(words_case[lower_query]);
                continue;
            }

            std::string devoweled_query = devowel(query);
            if (words_vowel.count(devoweled_query)) {
                result.push_back(words_vowel[devoweled_query]);
                continue;
            }
            
            result.push_back("");
        }

        return result;
    }

private:
    std::string toLower(const std::string& s) {
        std::string lower_s = s;
        std::transform(lower_s.begin(), lower_s.end(), lower_s.begin(),
                  [](unsigned char c){ return std::tolower(c); });
        return lower_s;
    }

    std::string devowel(const std::string& s) {
        std::string devoweled_s = toLower(s);
        for (char& c : devoweled_s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                c = '#';
            }
        }
        return devoweled_s;
    }
};