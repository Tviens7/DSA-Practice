class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int totalDrank = numBottles;
        int emptyBottles = numBottles;

        while (emptyBottles >= numExchange) {
            int newFullBottles = emptyBottles / numExchange;
            int remainingEmpty = emptyBottles % numExchange;
            
            totalDrank += newFullBottles;
            emptyBottles = remainingEmpty + newFullBottles;
        }
        
        return totalDrank;
    }
};