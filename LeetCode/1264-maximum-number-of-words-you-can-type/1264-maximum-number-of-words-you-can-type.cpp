class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int count = 0;
        bool newWord = true;

        for (char letter : text) {
            if (letter == ' ' && newWord) {
                ++count;
            }
            else if (letter == ' ') {
                newWord = true;
            }
            for (char broken : brokenLetters) {
                if (broken == letter) {
                    newWord = false;
                }
            }
        }
        if (newWord)
            ++count;
        return count;
    }
};