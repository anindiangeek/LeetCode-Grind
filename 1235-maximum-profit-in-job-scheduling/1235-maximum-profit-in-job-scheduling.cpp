class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
    {
        map<int, int> times;
    unordered_map<int, vector<pair<int, int>>> jobs;
    for (auto i = 0; i < startTime.size(); ++i) {
        times[startTime[i]] = 0;
        jobs[startTime[i]].push_back({ endTime[i], profit[i] });
    }    
    int max_profit = 0;
    for (auto it = rbegin(times); it != rend(times); ++it) {
        for (auto job : jobs[it->first]) {
            auto it = times.lower_bound(job.first);
            max_profit = max(max_profit, (it == end(times) ? 0 : it->second) + job.second);
        }
        it->second = max_profit;
    }
    return max_profit;
        
    }
};