class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets{};

        for (char c : s){
            if (c == '(' || c == '[' || c == '{')
                brackets.push(c);
            else if (!brackets.empty() && (c == ')' && brackets.top() == '(' ||
            c == ']' && brackets.top() == '[' || c == '}' && brackets.top() == '{'))
                brackets.pop();
            else
                return false;
        }
        return brackets.empty() ? true : false;
    }
};