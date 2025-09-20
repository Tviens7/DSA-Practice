#include <vector>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Router {
public:
    Router(int memoryLimit) : limit(memoryLimit), packet_id_counter(0) {}
    
    bool addPacket(int source, int destination, int timestamp) {
        std::tuple<int, int, int> packet_key = {source, destination, timestamp};
        if (packet_set.count(packet_key)) {
            return false;
        }

        if (packets.size() == limit) {
            auto oldest = packets.front();
            packets.pop_front();
            removePacketFromAuxiliary(oldest);
        }
        
        int current_id = packet_id_counter++;
        packets.emplace_back(source, destination, timestamp, current_id);
        packet_set.insert(packet_key);
        dest_timestamps[destination].insert({timestamp, current_id});
        
        return true;
    }
    
    std::vector<int> forwardPacket() {
        if (packets.empty()) {
            return {};
        }
        
        auto packet = packets.front();
        packets.pop_front();
        removePacketFromAuxiliary(packet);

        return {std::get<0>(packet), std::get<1>(packet), std::get<2>(packet)};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto it = dest_timestamps.find(destination);
        if (it == dest_timestamps.end()) {
            return 0;
        }

        auto& os = it->second;
        int end_count = os.order_of_key({endTime + 1, 0});
        int start_count = os.order_of_key({startTime, 0});
        
        return end_count - start_count;
    }

private:
    int limit;
    int packet_id_counter;
    std::deque<std::tuple<int, int, int, int>> packets;
    std::set<std::tuple<int, int, int>> packet_set;
    std::map<int, ordered_set<std::pair<int, int>>> dest_timestamps;

    void removePacketFromAuxiliary(const std::tuple<int, int, int, int>& packet) {
        int source = std::get<0>(packet);
        int dest = std::get<1>(packet);
        int ts = std::get<2>(packet);
        int id = std::get<3>(packet);
        
        packet_set.erase({source, dest, ts});
        
        auto& os = dest_timestamps.at(dest);
        os.erase({ts, id});

        if (os.empty()) {
            dest_timestamps.erase(dest);
        }
    }
};