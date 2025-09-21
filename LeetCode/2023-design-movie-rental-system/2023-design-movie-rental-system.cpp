class MovieRentingSystem {
public:
    MovieRentingSystem(int n, std::vector<std::vector<int>>& entries) {
        for (const auto& entry : entries) {
            int shop = entry[0];
            int movie = entry[1];
            int price = entry[2];
            movie_prices[{shop, movie}] = price;
            unrented_movies[movie].insert({price, shop});
        }
    }
    
    std::vector<int> search(int movie) {
        std::vector<int> result;
        if (unrented_movies.count(movie)) {
            int count = 0;
            for (const auto& [price, shop] : unrented_movies.at(movie)) {
                if (count == 5) {
                    break;
                }
                result.push_back(shop);
                count++;
            }
        }
        return result;
    }
    
    void rent(int shop, int movie) {
        int price = movie_prices.at({shop, movie});
        unrented_movies.at(movie).erase({price, shop});
        rented_movies.insert({price, shop, movie});
    }
    
    void drop(int shop, int movie) {
        int price = movie_prices.at({shop, movie});
        rented_movies.erase({price, shop, movie});
        unrented_movies[movie].insert({price, shop});
    }
    
    std::vector<std::vector<int>> report() {
        std::vector<std::vector<int>> result;
        int count = 0;
        for (const auto& [price, shop, movie] : rented_movies) {
            if (count == 5) {
                break;
            }
            result.push_back({shop, movie});
            count++;
        }
        return result;
    }

private:
    std::map<std::pair<int, int>, int> movie_prices;
    std::map<int, std::set<std::pair<int, int>>> unrented_movies;
    std::set<std::tuple<int, int, int>> rented_movies;
};