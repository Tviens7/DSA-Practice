class TaskManager {
public:
    TaskManager(std::vector<std::vector<int>>& tasks) {
        for (const auto& task : tasks) {
            int userId = task[0];
            int taskId = task[1];
            int priority = task[2];
            
            task_info[taskId] = {userId, priority};
            pq.push({priority, taskId});
        }
    }

    void add(int userId, int taskId, int priority) {
        task_info[taskId] = {userId, priority};
        pq.push({priority, taskId});
    }

    void edit(int taskId, int newPriority) {
        task_info[taskId].second = newPriority;
        

        pq.push({newPriority, taskId});
    }
    

    void rmv(int taskId) {
        task_info.erase(taskId);
    }

    int execTop() {
        while (!pq.empty()) {
            int top_taskId = pq.top().second;
            int top_priority = pq.top().first;

            if (task_info.find(top_taskId) == task_info.end()) {
                pq.pop();
                continue;
            }
            
            if (task_info[top_taskId].second != top_priority) {
                pq.pop();
                continue;
            }
            
            break; 
        }

        if (pq.empty()) {
            return -1;
        }

        int taskId_to_exec = pq.top().second;
        int userId_to_return = task_info[taskId_to_exec].first;
        
        pq.pop();
        task_info.erase(taskId_to_exec);
        
        return userId_to_return;
    }

private:

    std::priority_queue<std::pair<int, int>> pq;

    std::unordered_map<int, std::pair<int, int>> task_info;
};
