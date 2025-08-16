class Solution {
public:
    int maximum69Number (int num) {
        std::string newNum;
        bool changed = false;
        for (char num : std::to_string(num)){
            if (num == '6' && !changed){
                newNum += '9';
                changed = true;
            } else {
                newNum += num;
            }
            
        }
        return std::stoi(newNum);
    }
};