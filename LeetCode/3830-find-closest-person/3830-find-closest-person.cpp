class Solution {
public:
    int findClosest(int x, int y, int z) {
        int one = x - z;
        int two = y - z;
        if (one < 0)
            one *= -1;
        if (two < 0)
            two *= -1;
        if (one == two)
            return 0;
        return one > two ? 2 : 1;
    }
};