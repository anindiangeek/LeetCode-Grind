class Solution {
public:
    vector<int> Left(vector<int> &heights)
    {
        vector<int> v((int)heights.size());
        stack<pair<int,int>>s;
        
        for(int i=0;i<heights.size();i++)
        {
            while(!s.empty() && s.top().second >=heights[i])
                    s.pop();
            v[i] =s.empty()?-1:s.top().first;
            s.push({i,heights[i]});
        }
        return v;
    }
    vector<int> Right(vector<int> &heights)
    {
        vector<int> v((int)heights.size());
        stack<pair<int,int>>s;
        
        for(int i=heights.size()-1;i>=0;i--)
        {
            while(!s.empty() && s.top().second >=heights[i])
                    s.pop();
            v[i] =s.empty()?heights.size():s.top().first;
            s.push({i,heights[i]});
        }
        return v;  
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> NSL= Left(heights);
        vector<int> NSR= Right(heights);
        int answer=INT_MIN;
        for(int i=0;i<heights.size();i++)
            answer=max(answer,heights[i] * (NSR[i]-NSL[i]-1));
        return answer;
    }
};