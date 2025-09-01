class Solution {
public:
    double maxAverageRatio(std::vector<std::vector<int>>& classes, int extraStudents) {
        std::priority_queue<std::pair<double, int>> max_heap;

        auto calculate_gain = [](int pass, int total) {
            return static_cast<double>(pass + 1) / (total + 1) - static_cast<double>(pass) / total;
        };

        for (int i = 0; i < classes.size(); ++i) {
            max_heap.push({calculate_gain(classes[i][0], classes[i][1]), i});
        }

        while (extraStudents-- > 0) {
            int class_index = max_heap.top().second;
            max_heap.pop();

            classes[class_index][0]++;
            classes[class_index][1]++;
            
            max_heap.push({calculate_gain(classes[class_index][0], classes[class_index][1]), class_index});
        }

        double total_ratio_sum = 0.0;
        for (const auto& c : classes) {
            total_ratio_sum += static_cast<double>(c[0]) / c[1];
        }

        return total_ratio_sum / classes.size();
    }
};