class Solution {
public:
    int minSetSize(vector<int>& arr) 
    {
        int n=arr.size();
        int target = n/2;
        
        map<int,int> Hash;
        for(auto val:arr)
            Hash[val]++;
        
        priority_queue<int> pq;
        
        for(auto it=Hash.begin();it!=Hash.end();it++)
            pq.push(it->second);
        
        int count = 0;
        while(!pq.empty() and n>target)
        {
            int temp = pq.top();
            pq.pop();
            n-=temp;
            count++;
        }
        return count;
        
        
        
    }
};