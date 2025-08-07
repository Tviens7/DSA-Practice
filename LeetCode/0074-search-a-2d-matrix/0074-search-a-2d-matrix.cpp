class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left_v = 0;
        int right_v = matrix.size() - 1;

        while (left_v <= right_v){
            int mid_v = left_v + (right_v - left_v) / 2;
            

            if (target >= matrix[mid_v][0] && target <= matrix[mid_v][matrix[mid_v].size() - 1]){
                int left = 0;
                int right = matrix[mid_v].size() - 1;

                while (left <= right){
                    int mid = left + (right - left) / 2;

                    if (matrix[mid_v][mid] == target)
                        return true;
                    else if (matrix[mid_v][mid] > target)
                        right = mid - 1;
                    else
                        left = mid + 1;
                }
                return false;
            }
            else if (target < matrix[mid_v][0]){
                right_v = mid_v - 1;
            }
            else{
                left_v = mid_v + 1;
            }
        }
        return false;
    }
};