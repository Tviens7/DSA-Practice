class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int max = 0;
        int area = 0;
        for (const auto& rec : dimensions){
            int current = rec[0]*rec[0] + rec[1]*rec[1];
            if (current > max){
                max = current;
                area = rec[0]*rec[1];
            }
            else if (current == max){
                if (rec[0]*rec[1] > area)
                    area = rec[0]*rec[1];
            }
        }
        return area;
    }
};