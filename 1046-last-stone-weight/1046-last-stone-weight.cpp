class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(auto item : stones)
            pq.push(item);
        
        while(pq.size()>1)
        {
            int i1=pq.top();
            pq.pop();
            int i2=pq.top();
            pq.pop();
            if(i1==i2) continue;
            else
                pq.push(i1-i2);
        }
        return pq.size()?pq.top():0;
    }
};