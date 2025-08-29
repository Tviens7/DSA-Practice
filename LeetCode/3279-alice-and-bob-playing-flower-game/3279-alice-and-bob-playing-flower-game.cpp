class Solution {
public:
    long long flowerGame(int n, int m) {
        long long N = n;
        long long M = m;

        long long n_odd_count = (N + 1) / 2;
        long long n_even_count = N / 2;

        long long m_odd_count = (M + 1) / 2;
        long long m_even_count = M / 2;

        long long odd_even_pairs = n_odd_count * m_even_count;
        long long even_odd_pairs = n_even_count * m_odd_count;

        return odd_even_pairs + even_odd_pairs;
    }
};