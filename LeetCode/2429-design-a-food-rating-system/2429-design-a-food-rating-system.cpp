class FoodRatings {
private:
    std::unordered_map<std::string, std::pair<std::string, int>> food_info;

    std::unordered_map<std::string, std::set<std::pair<int, std::string>>> cuisine_to_foods;

public:
    FoodRatings(std::vector<std::string>& foods, std::vector<std::string>& cuisines, std::vector<int>& ratings) {
        for (int i = 0; i < foods.size(); ++i) {
            food_info[foods[i]] = {cuisines[i], ratings[i]};
            cuisine_to_foods[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }

    void changeRating(std::string food, int newRating) {
        auto& info = food_info[food];
        std::string cuisine = info.first;
        int oldRating = info.second;

        cuisine_to_foods[cuisine].erase({-oldRating, food});

        cuisine_to_foods[cuisine].insert({-newRating, food});

        info.second = newRating;
    }

    std::string highestRated(std::string cuisine) {
        return cuisine_to_foods[cuisine].begin()->second;
    }
};