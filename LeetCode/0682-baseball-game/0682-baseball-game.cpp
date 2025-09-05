class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> scores;

        for (string score : operations) {
            if (score == "+") {
                int score2 = scores.top();
                scores.pop();
                int score1 = scores.top();
                scores.pop();
                int sum = score1 + score2;
                scores.push(score1);
                scores.push(score2);
                scores.push(sum);
            }
            else if (score == "C") {
                scores.pop();
            }
            else if (score == "D") {
                scores.push(scores.top()*2);
            }
            else {
                scores.push(stoi(score));
            }
        }

        int sum = 0;

        while (!scores.empty()) {
            sum += scores.top();
            scores.pop();
        }

        return sum;
    }
};