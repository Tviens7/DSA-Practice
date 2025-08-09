class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lowBound = 1;
        int highBound = *std::max_element(piles.begin(), piles.end());
        int answer = highBound;

        while (lowBound <= highBound){
            int mid = lowBound + (highBound - lowBound) / 2;
            long hours_needed = 0;

            for (int pile : piles){
                hours_needed += (pile + mid - 1) / mid;
            }

            if (hours_needed <= h) {
                answer = mid;
                highBound = mid - 1;
            } else {
                lowBound = mid + 1;
            }

        }

        return answer;
    }
};