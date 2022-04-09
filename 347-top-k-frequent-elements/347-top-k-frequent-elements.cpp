class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        map<int,int> FrequencyMap;
        for(int i : nums) FrequencyMap[i]++;
        
        auto comp = [&FrequencyMap](int n1, int n2) { return FrequencyMap[n1] >      FrequencyMap[n2]; };
        
        priority_queue<int, vector<int>, decltype(comp)> heap(comp);
        
        for (pair<int, int> p : FrequencyMap) {
            heap.push(p.first);
            if (heap.size() > k) heap.pop();
        }
        
        vector<int> top(k);
        for (int i = k - 1; i >= 0; i--) {
            top[i] = heap.top();
            heap.pop();
        }
        
        return top;
    }
    
};