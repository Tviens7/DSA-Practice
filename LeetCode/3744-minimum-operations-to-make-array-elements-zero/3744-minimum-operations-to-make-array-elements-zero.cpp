#include <vector>
#include <algorithm> // For std::max

class Solution {
public:
    /**
     * Calculates the sum of ops(i) for all i from 1 to N.
     * ops(i) is the number of divisions by 4 needed to make i zero.
     */
    long long sum_ops(long long N) {
        if (N <= 0) {
            return 0;
        }
        long long total_ops_sum = 0;
        long long power_of_4 = 1;
        long long k = 1;

        while (power_of_4 <= N / 4) {
            long long next_power_of_4 = power_of_4 * 4;
            long long count_in_range = next_power_of_4 - power_of_4;
            total_ops_sum += k * count_in_range;
            power_of_4 = next_power_of_4;
            k++;
        }

        long long count_in_last_range = N - power_of_4 + 1;
        total_ops_sum += k * count_in_last_range;

        return total_ops_sum;
    }

    long long minOperations(std::vector<std::vector<int>>& queries) {
        long long total_result = 0;
        for (const auto& query : queries) {
            long long l = query[0];
            long long r = query[1];
            
            // n: The number of elements in the array [l, r]
            long long n = r - l + 1;
            
            // P: The total potential of the array
            long long P = sum_ops(r) - sum_ops(l - 1);
            
            // The ceiling of P/2, calculated using integer division
            long long ceil_p_div_2 = (P + 1) / 2;
            
            // The correct answer is the max of the two lower bounds
            long long ops_for_query = std::max(n - 1, ceil_p_div_2);
            
            total_result += ops_for_query;
        }
        return total_result;
    }
};