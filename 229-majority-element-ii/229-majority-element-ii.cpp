class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> answer;

        unordered_map<int, int> HashMap;

        int times = nums.size() / 3; // k times

        for (auto &value : nums)
            HashMap[value]++;

        for (auto itr = HashMap.begin(); itr != HashMap.end(); itr++) // itr is an iterator.
            if (itr->second > times)
                answer.emplace_back(itr->first);

        return answer;
    }
};